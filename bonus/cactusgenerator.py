import os
import time
import subprocess
import concurrent.futures
import matplotlib.pyplot as plt

# Paths and configurations
cnf_directory = "/Users/kovid/Downloads/satsolver"
cnf_files = sorted([os.path.join(cnf_directory, f) for f in os.listdir(cnf_directory) if f.endswith('.cnf')])[:20]  # Sort CNF files and limit to first 20
elim_values = [0, 5, 10]  # Adjust values for --elim parameter
timeout = 900  # 900-second timeout per instance

# Function to run Lingeling with specified elim parameter and capture runtime
def run_lingeling(cnf_file, elim_value):
    command = ['./lingeling', f'--elim={elim_value}', cnf_file]
    print(f"Running Lingeling on {cnf_file} with --elim={elim_value}")
    start_time = time.time()
    try:
        result = subprocess.run(command, capture_output=True, text=True, timeout=timeout)
        end_time = time.time()
        status = 'UNSAT' if 'UNSATISFIABLE' in result.stdout else 'SAT' if 'SATISFIABLE' in result.stdout else 'UNKNOWN'
        runtime = end_time - start_time
        print(f"Completed {cnf_file} in {runtime:.3f} seconds with status {status}")
        return runtime
    except subprocess.TimeoutExpired:
        print(f"Timed out on {cnf_file}")
        return timeout

# Run benchmarks in parallel
def benchmark_elim(elim_value):
    with concurrent.futures.ThreadPoolExecutor() as executor:
        times = list(executor.map(lambda cnf_file: run_lingeling(cnf_file, elim_value), cnf_files))
    print(f"Times for --elim={elim_value}: {times}")
    return times

# Collect results for each elim value
results = {elim_value: benchmark_elim(elim_value) for elim_value in elim_values}

# Prepare data for cactus plot
cumulative_solved = {}
for elim_value, times in results.items():
    cumulative_times = []
    total_time = 0
    for time in times:
        total_time += time
        cumulative_times.append(total_time)
    cumulative_solved[elim_value] = cumulative_times

# Generate cactus plot and save as PNG
plt.figure(figsize=(10, 6))
for elim_value, cumulative in cumulative_solved.items():
    plt.plot(range(1, len(cumulative) + 1), cumulative, label=f'--elim={elim_value}')
plt.xlabel("Number of Instances Solved")
plt.ylabel("Cumulative Solving Time (s)")
plt.title("Cactus Plot of Lingeling Performance for Different --elim Values")
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.savefig("cactus_plot_lingeling.png")
print("Cactus plot saved as 'cactus_plot_lingeling.png'")
