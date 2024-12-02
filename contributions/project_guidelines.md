# Qt Network Test Project

This project is a simple Qt-based application that demonstrates client-server communication. It involves sending a paragraph of text from the client to the server, which processes the request by forwarding it to OpenAI's API. The server then handles the response and can perform further operations as needed.

---

## Project Overview

### 1. Client
The client project is a Qt Widgets application that provides a user interface with:
- A 500-character message box for entering a paragraph of text.
- Input fields for server IP and port.
- A button to send the message to the server.

### 2. Server
The server project is a daemon application that:
- Listens on a specified port for incoming client connections.
- Accepts and processes text requests from clients.
- (Future implementation) Sends the received text to OpenAI's API and handles the response.

### 3. Shared
The shared library provides utility functions, such as:
- **IP address validation:** Ensures the server IP entered by the client is in a valid format.
-
---

## Dependencies

- **Qt 6:** Required for GUI (client) and networking components (client and server).
- **C++17 or later:** For modern C++ features.
- **(Future)** OpenAI API key: Required for server-side API requests.

---

## Building the Project

### Prerequisites
1. Install **Qt 6** and **CMake** on your system.
2. Clone the repository:
   ```bash
   git clone <repository_url>
   cd qt_network_test
   ```

### Build Instructions
1. Create a build directory:
   ```bash
   mkdir build
   cd build
   ```
2. Configure the project:
   ```bash
   cmake ..
   ```
3. Build the project:
   ```bash
   make
   ```

### Run the Applications
- **Client:**
  ```bash
  ./client/ClientApp
  ```
- **Server:**
  ```bash
  ./server/ServerApp
  ```

---

## Usage

### Client
1. Launch the `ClientApp` executable.
2. Enter:
    - A paragraph of text (up to 500 characters).
    - The server's IP address.
    - The port number the server is listening on.
3. Click the **"Send to Server"** button to send the request.

### Server
1. Launch the `ServerApp` executable.
2. The server will start listening for incoming connections on the specified port (default is 12345).
3. Once a client connects and sends data, the server processes the request (future implementation: forwards it to OpenAI's API).

---

## Future Enhancements

### OpenAI Integration
- Add server-side logic to forward client text to OpenAI's API.
- Handle API responses and return them to the client.

### Shared Enhancements
- Extend the shared library to include more utilities, such as port validation and request formatting.

### Error Handling
- Improve error reporting and user feedback in both client and server applications.

### Scalability
- Allow the server to handle multiple clients concurrently.
- Implement threading for better performance.

---

## Contributing

Contributions are welcome! If you’d like to improve this project:
1. Fork the repository.
2. Make your changes.
3. Open a pull request.

Before contributing, please review the [Project Guidelines](./contributions/project_guidelines.md) for details on coding conventions, file structure, and other best practices.

---

## License

This project is licensed under the MIT License. See the `LICENSE` file for details.

---

### Changes Added
- **Contributing Section:** Added a link to `./contributions/project_guidelines.md` for detailed guidelines.
- **Structured and formatted the document** for clarity and readability.