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

---



\## Usage

| Command | Description | Example |

|----------|--------------|----------|

| `add_task -name {Task}` | Add a new task | `add_task -name {Buy milk}` |

| `remove_task -name {Task}` | Remove a task | `remove_task -name {Buy milk}` |

| `complete_task -name {Task}` | Mark as completed | `complete_task -name {Buy milk}` |

| `list_tasks` | List all tasks | `list_tasks` |

| `execute_file -file_path {path}` | Execute commands from file | `execute_file -file_path {..\commands.txt}` |



---

