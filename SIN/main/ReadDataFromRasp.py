import subprocess
import threading

shared_data = {"latest_value": ""}

def run_impulse():
    process = subprocess.Popen(
        ["python", "-u", "Impulse.py"], # Replace the command with the actual one, but keep the -u argument to enable 'unbuffering'
        stdout=subprocess.PIPE,
        stderr=subprocess.STDOUT,
        bufsize=1,
        text=True
    )

    for line in iter(process.stdout.readline, ''):
        if line.strip():
            shared_data["latest_value"] = line.strip()

    process.stdout.close()
    process.wait()

def start_impulse_in_background():
    thread = threading.Thread(target=run_impulse, daemon=True)
    thread.start()
