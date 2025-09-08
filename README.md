# TCP Server in C
A lightweight TCP server built in C to demonstrate socket programming and network communication fundamentals. The server listens on port 8080, accepts incoming connections, and displays client messages in real time.


## How to build and run:
1.) Clone the repository


```git clone https://github.com/zasut/TCP-server```


 ```cd TCP-server```

2,) Compile the server

```gcc server.c -o server```


3.) Run the server

```./server```

**You should see**

```Server listening on port 8080```

4.) Test the server

**Open a new terminal and run**


```nc localhost 8080```

**Afterwards type a message, example:**

```Hello Server!```

**The server terminal will display:**

```Client: Hello Server!```


## How It's Made:

**Tech used:** C, POSIX sockets, macOS/Linux terminal


This project was built to practice low-level network programming concepts. The server goes through all the core steps of TCP socket communication:


1.) Create a socket with socket().


2.) Configure it with setsockopt() to allow reuse.


3.) Bind it to a local address and port.


4.) Listen for incoming client connections.


5.) Accept a client connection with accept().


6.) Read incoming messages using read().


Testing was done via Netcat (nc) and the server was verified on macOS, with Linux compatibility.

## Lessons Learned:
Learned how to build a TCP server from scratch using only C and system libraries.
Gained hands-on understanding of how sockets, ports, and connections actually work at the OS level.





