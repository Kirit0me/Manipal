import socket
import threading


def caesar_cipher(msg, key):
    print("Original Message : ", msg)
    result = ""
    for char in msg:
        if char.isupper():
            result += chr((ord(char) + key - 65) % 26 + 65)
        elif char.islower():
            result += chr((ord(char) + key - 97) % 26 + 97)
        else:
            result += char

    return result


def receive_messages(client_socket):
    while True:
        try:
            response = client_socket.recv(1024).decode()
            if not response:
                break
            print(f"Received: {response}")
        except ConnectionResetError:
            break


def main():
    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client.connect(("localhost", 9992))

    receive_thread = threading.Thread(target=receive_messages, args=(client,))
    receive_thread.start()

    while True:
        message = input(": ")
        if message.lower() == "exit":
            break
        client.send(caesar_cipher(message, 5).encode())

    client.close()


if __name__ == "__main__":
    main()
