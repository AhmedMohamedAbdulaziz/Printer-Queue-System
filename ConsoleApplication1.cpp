#include <iostream>
#include <cstring>
using namespace std;

struct PrintJob {
    char fileName[100];
    int pages;
};

class PrinterQueue {
private:
    PrintJob jobs[100];
    int front, rear;

public:
    PrinterQueue() {
        front = rear = -1;
    }

    bool isEmpty() { return front == -1; }

    void enqueue(PrintJob job) {
        if (rear == 99) {
            cout << "Queue is full!\n";
            return;
        }
        if (front == -1) front = 0;
        jobs[++rear] = job;
    }

    PrintJob dequeue() {
        PrintJob temp;
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            strcpy_s(temp.fileName, sizeof(temp.fileName), "None");
            temp.pages = 0;
            return temp;
        }

        temp = jobs[front];
        if (front == rear)
            front = rear = -1;
        else
            front++;
        return temp;
    }

    void display() {
        if (isEmpty()) {
            cout << "No pending print jobs.\n";
            return;
        }
        cout << "\nPending Jobs:\n";
        for (int i = front; i <= rear; i++) {
            cout << i - front + 1 << ". " << jobs[i].fileName
                << " (" << jobs[i].pages << " pages)\n";
        }
    }
};

class UndoStack {
private:
    PrintJob stack[100];
    int top;

public:
    UndoStack() { top = -1; }

    bool isEmpty() { return top == -1; }

    void push(PrintJob job) {
        if (top == 99) {
            cout << "Stack full!\n";
            return;
        }
        stack[++top] = job;
    }

    PrintJob pop() {
        PrintJob temp;
        if (isEmpty()) {
            strcpy_s(temp.fileName, sizeof(temp.fileName), "None");
            temp.pages = 0;
            return temp;
        }
        return stack[top--];
    }
};

class History {
private:
    PrintJob* printed;
    int size;

public:
    History() {
        printed = nullptr;
        size = 0;
    }

    void add(PrintJob job) {
        PrintJob* newArr = new PrintJob[size + 1];
        for (int i = 0; i < size; i++)
            newArr[i] = printed[i];
        newArr[size++] = job;
        delete[] printed;
        printed = newArr;
    }

    void removeLast() {
        if (size == 0) return;
        size--;
    }

    void show() {
        if (size == 0) {
            cout << "No history available.\n";
            return;
        }
        cout << "\nPrinting History:\n";
        for (int i = 0; i < size; i++) {
            cout << i + 1 << ". " << printed[i].fileName
                << " (" << printed[i].pages << " pages)\n";
        }
    }
};

// ==================== MAIN PROGRAM ====================
int main() {
    PrinterQueue queue;
    UndoStack undo;
    History history;

    int choice;
    do {
        cout << "\n===== PRINTER QUEUE SYSTEM =====\n";
        cout << "1. Add new print job\n";
        cout << "2. Show pending jobs\n";
        cout << "3. Print next job\n";
        cout << "4. Undo last print\n";
        cout << "5. Show history\n";
        cout << "6. Exit\n";
        cout << "=================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            PrintJob job;
            cout << "Enter file name: ";
            cin >> job.fileName;
            cout << "Enter number of pages: ";
            cin >> job.pages;
            queue.enqueue(job);
            cout << "Job added!\n";
        }

        else if (choice == 2)
            queue.display();

        else if (choice == 3) {
            if (queue.isEmpty()) {
                cout << "No jobs to print.\n";
                continue;
            }
            PrintJob job = queue.dequeue();
            cout << "Printing \"" << job.fileName << "\" (" << job.pages << " pages)...\n";
            history.add(job);
            undo.push(job);
            cout << "Print complete!\n";
        }

        else if (choice == 4) {
            if (undo.isEmpty()) {
                cout << "No print to undo.\n";
                continue;
            }
            PrintJob last = undo.pop();
            queue.enqueue(last);
            history.removeLast();
            cout << "Undid print for \"" << last.fileName << "\".\n";
        }

        else if (choice == 5)
            history.show();

        else if (choice == 6)
            cout << " Exiting system...\n";

        else
            cout << "Invalid choice!\n";

    } while (choice != 6);

    return 0;
}
