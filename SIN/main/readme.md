# Changes needed to be done:
- Try a python IDE instead of hardcoding all the tim: (vscode)[https://code.visualstudio.com/docs/editor/portable].
- Reformat function.
- Allow P2P communication seemlessly:
  - Use a Separate Thread for Listening:
    
    logger.py:
    ```python
    from datetime import datetime

    def log_message(direction, message):
        with open("message_log.txt", "a") as f:
            now = datetime.now().strftime('%Y-%m-%d %H:%M:%S')
            f.write(f"[{now}] {direction}: {message.strip()}\n")
    ```
    
    communication.py:
    ```python
    import time
    import threading
    from logger import log_message

    # Instead of GET():
    def listen():
    while listening:
        try:
            if ser.in_waiting > 0:
                line = ser.readline().decode('utf-8').strip()
                if line:
                    print(f"← Arduino: {line}")
                    log_message("← Arduino", line)
        except Exception as e:
            print(f"[ERROR in listener] {e}")

    listener_thread = threading.Thread(target=listen, daemon=True)
    listener_thread.start()
    ```

    main.py:
    ```python
    # main.py
    from communication import POST
    from time import sleep
    
    while True:
        # We don't need to try to get any message: They are already logged in the log file.
        msg = input("Enter message to send to Arduino: ")
        POST(msg)
        sleep(0.5)
    ```
