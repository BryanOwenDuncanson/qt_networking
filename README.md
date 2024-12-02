# **Qt Network Test Project**

This project is a simple Qt-based application that demonstrates client-server communication. It involves sending a paragraph of text from the client to the server, which processes the request by forwarding it to OpenAI's API. The server then handles the response and can perform further operations as needed.

---

## **Project Overview**

### **1. Client**
The `client` project is a Qt Widgets application that provides a user interface with:
- A **500-character message box** for entering a paragraph of text.
- Input fields for **server IP** and **port**.
- A button to **send the message** to the server.

### **2. Server**
The `server` project is a daemon application that:
- Listens on a specified port for incoming client connections.
- Accepts and processes text requests from clients.
- (Future implementation) Sends the received text to OpenAI's API and handles the response.

### **3. Shared**
The `shared` library provides utility functions, such as:
- **IP address validation**: Ensures the server IP entered by the client is in a valid format.

---

## **Project Structure**

The project is organized into the following subdirectories:

```plaintext
qt_network_test/
├── client/         # The client application
│   ├── include/    # Header files
│   ├── src/        # Source files
│   └── CMakeLists.txt
├── server/         # The server daemon
│   ├── include/    # Header files
│   ├── src/        # Source files
│   └── CMakeLists.txt
├── shared/         # Shared library for utilities
│   ├── include/    # Header files
│   ├── src/        # Source files
│   └── CMakeLists.txt
└── CMakeLists.txt  # Root CMake configuration
```

---

## **Dependencies**

- **Qt 6**: Required for GUI (client) and networking components (client and server).
- **C++17 or later**: For modern C++ features.
- (Future) **OpenAI API key**: Required for server-side API requests.

---

## **Building the Project**

### Prerequisites

1. Install Qt 6 and CMake on your system.
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

4. Run the applications:
   - **Client**:
     ```bash
     ./client/ClientApp
     ```
   - **Server**:
     ```bash
     ./server/ServerApp
     ```

---

## **Usage**

### **Client**
1. Launch the `ClientApp` executable.
2. Enter:
   - A paragraph of text (up to 500 characters).
   - The server's IP address.
   - The port number the server is listening on.
3. Click the **"Send to Server"** button to send the request.

### **Server**
1. Launch the `ServerApp` executable.
2. The server will start listening for incoming connections on the specified port (default is `12345`).
3. Once a client connects and sends data, the server processes the request (future implementation: forwards it to OpenAI's API).

---

## **Future Enhancements**

1. **OpenAI Integration**:
   - Add server-side logic to forward client text to OpenAI's API.
   - Handle API responses and return them to the client.

2. **Shared Enhancements**:
   - Extend the shared library to include more utilities, such as port validation and request formatting.

3. **Error Handling**:
   - Improve error reporting and user feedback in both client and server applications.

4. **Scalability**:
   - Allow the server to handle multiple clients concurrently.
   - Implement threading for better performance.

---

## **Contributing**

Contributions are welcome! If you’d like to improve this project, feel free to fork the repository, make your changes, and open a pull request.

---

## **License**

This project is licensed under the MIT License. See the `LICENSE` file for details.
