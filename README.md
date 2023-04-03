# task-scheduling
I address the problem of scheduling tasks that have dependencies between each other, with the only guarantee that there are no circular dependencies. 

First, formalize the problem as a directed acyclic graph (DAG) and describe two algorithms for topological sorting to determine a valid order to complete the tasks.

Then consider the case where each task has a known duration and the tasks can be performed in parallel (with unlimited workers)
