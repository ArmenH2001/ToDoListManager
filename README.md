\# To-Do List Manager (Qt Project)



\## Overview

This is a simple command-driven \*\*To-Do list application\*\* built with \*\*Qt 6 / C++\*\*.  

The goal of the project is to demonstrate clean architecture and the \*\*Command Pattern\*\* in Qt.



Users can type commands such as:

&nbsp;	add\_task -name {Buy milk}

&nbsp;	complete\_task -name {Buy milk}

&nbsp;	list\_tasks

and the model executes them, updating the task list accordingly.



---



\## Design Summary

\- \*\*CommandParser\*\* — reads a text command, extracts the command name and all `-flag {argument}` pairs.  

\- \*\*CommandFactory\*\* — checks the parsed data and creates the proper command object.  

\- \*\*ICommand + derived classes\*\* — `AddTaskCommand`, `RemoveTaskCommand`, `CompleteTaskCommand`, `ListTasksCommand`, `ExecuteFileCommand`.  

\- \*\*ToDoListManagerModel\*\* — holds all tasks and emits Qt signals (`log`, `task`, `requestClearTaskList`) to the UI.  

\- \*\*Task\*\* — represents one task with a name and completion state.  



The structure makes the system easily extendable: to add a new command or flag, create a new `ICommand` subclass and register it in `CommandFactory`.



---



\## Build \& Run

\*\*Requirements\*\*

\- Qt 6.5+  

\- C++17 or later  

\- Tested on Windows 11 / Qt Creator 10



\*\*Steps\*\*

1\. Open the project file `ToDoListManager.pro` in \*\*Qt Creator\*\*.  

2\. Select a Qt kit (MinGW or MSVC).  

3\. Build the project (`Ctrl + B`).  

4\. Run (`Ctrl + R`).  



---



\## Usage

| Command | Description | Example |

|----------|--------------|----------|

| `add\_task -name {Task}` | Add a new task | `add\_task -name {Buy milk}` |

| `remove\_task -name {Task}` | Remove a task | `remove\_task -name {Buy milk}` |

| `complete\_task -name {Task}` | Mark as completed | `complete\_task -name {Buy milk}` |

| `list\_tasks` | List all tasks | `list\_tasks` |

| `execute\_file -file\_path {path}` | Execute commands from file | `execute\_file -file\_path {commands.txt}` |



---

