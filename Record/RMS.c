#include <stdio.h>
#include <stdlib.h>

// Structure to represent a task
typedef struct {
    int id;             // Task ID
    int period;         // Task period
    int execution_time; // Task execution time
    int next_deadline;  // Next deadline of the task
} Task;

// Function to compare tasks based on their periods (for sorting)
int compare_tasks(const void *a, const void *b) {
    return ((Task *)a)->period - ((Task *)b)->period;
}

// Function to perform Rate Monotonic Scheduling
void rate_monotonic_scheduling(Task tasks[], int num_tasks, int total_time) {
    // Sort tasks based on their periods (shortest period first)
    qsort(tasks, num_tasks, sizeof(Task), compare_tasks);

    // Initialize task deadlines
    for (int i = 0; i < num_tasks; i++) {
        tasks[i].next_deadline = tasks[i].period;
    }

    printf("Time\t");
    for (int i = 0; i < num_tasks; i++) {
        printf("Task %d\t", tasks[i].id);
    }
    printf("\n");

    // Simulate scheduling for the given total time
    for (int current_time = 0; current_time < total_time; current_time++) {
        printf("%d\t", current_time);
        int executed_task = -1; // Initialize to no task executed

        // Find the highest priority task that is ready to execute
        for (int i = 0; i < num_tasks; i++) {
            if (current_time % tasks[i].period == 0) {
                tasks[i].next_deadline = current_time + tasks[i].period; // Update next deadline
            }
            if (current_time < tasks[i].next_deadline) {
                executed_task = i;
                break; // Execute the highest priority task
            }
        }

        // Execute the selected task (if any)
        if (executed_task != -1) {
            for (int i = 0; i < num_tasks; i++) {
                if (i == executed_task) {
                    printf("Executing\t");
                } else {
                    printf("\t");
                }
            }
        } else {
             for (int i = 0; i < num_tasks; i++) {
                printf("\t");
            }
        }
        printf("\n");
    }
}

int main() {
    // Example tasks
    Task tasks[] = {
        {1, 20, 10}, // Task 1: period 20, execution time 10
        {2, 50, 15}, // Task 2: period 50, execution time 15
        {3, 100, 5}  // Task 3: period 100, execution time 5
    };
    int num_tasks = sizeof(tasks) / sizeof(tasks[0]);
    int total_time = 200; // Total simulation time

    // Perform Rate Monotonic Scheduling
    rate_monotonic_scheduling(tasks, num_tasks, total_time);

    return 0;
}
