# 🖨️ Printer-Queue-System

You are asked to build a **Printer Queue Simulation System** that manages print jobs in a queue.  
Users can **add new print jobs**, **view the waiting list**, **print the next document**, **undo the last print**, and **view the printing history** — all through a clear and well-designed **console interface**.

---

## 🎯 Project Overview

The project simulates how a **real printer queue** works in an office or lab environment using **basic data structures implemented manually** in C++ (without STL).  
It demonstrates **Queue**, **Stack**, and **Dynamic Array** operations and provides practical insight into process management and memory handling.

---

## ⚙️ Core Functionalities

| Feature | Description |
|----------|-------------|
| ➕ **Add New Print Job** | Input file name and page count, then add to the print queue (FIFO). |
| 📄 **Show Pending Jobs** | Displays all jobs currently waiting to be printed. |
| 🖨️ **Print Next Job** | Removes the first job from the queue and stores it in print history. |
| ↩️ **Undo Last Print** | Uses a stack to move the last printed job back to the queue. |
| 📜 **Show Print History** | Displays all previously printed jobs stored in a dynamic array. |
| ❌ **Exit** | Closes the program safely. |

---

## 🧱 Data Structures Used

| Data Structure | Purpose |
|----------------|----------|
| **Queue** | Stores all pending print jobs (FIFO order). |
| **Stack** | Holds the recently printed job to allow undo functionality. |
| **Dynamic Array** | Keeps a list of all printed jobs as history. |

All of these are implemented manually using arrays and classes — **no STL containers** like `queue`, `stack`, or `vector` are used.

---


