/**
 * @file gpu_device.c
 * @brief A simple state machine to manage the GPU's current state.
 * This simulates a GPU that transitions between different states based on commands.
 */

#include <stdbool.h>
#include <string.h>

/**
 * @brief Enum representing the possible states of the GPU.
 */
typedef enum {
    WAITING_FOR_COMMAND, /**< GPU is waiting for a command. */
    PROCESSING_COMMAND,  /**< GPU is processing the command. */
    EXECUTING_TASK,      /**< GPU is executing the task. */
    COMPLETED_TASK       /**< GPU has completed the task. */
} GpuState;

/**
 * @brief GPU device state management.
 */
typedef struct {
    GpuState current_state; /**< Current state of the GPU. */
} GpuDevice;

/**
 * @brief Initializes the GPU device to the initial state.
 * @param gpu Pointer to the GPU device.
 */
void initGpuDevice(GpuDevice *gpu) {
    gpu->current_state = WAITING_FOR_COMMAND;
}

/**
 * @brief Receives a command, transitioning from WAITING_FOR_COMMAND to PROCESSING_COMMAND.
 * @param gpu Pointer to the GPU device.
 */
void receiveCommand(GpuDevice *gpu) {
    if (gpu->current_state == WAITING_FOR_COMMAND) {
        gpu->current_state = PROCESSING_COMMAND;
    }
}

/**
 * @brief Processes the command, transitioning from PROCESSING_COMMAND to EXECUTING_TASK.
 * @param gpu Pointer to the GPU device.
 */
void processCommand(GpuDevice *gpu) {
    if (gpu->current_state == PROCESSING_COMMAND) {
        gpu->current_state = EXECUTING_TASK;
    }
}

/**
 * @brief Completes the task, transitioning from EXECUTING_TASK to COMPLETED_TASK.
 * @param gpu Pointer to the GPU device.
 */
void completeTask(GpuDevice *gpu) {
    if (gpu->current_state == EXECUTING_TASK) {
        gpu->current_state = COMPLETED_TASK;
    }
}

/**
 * @brief Resets the GPU state, transitioning from COMPLETED_TASK to WAITING_FOR_COMMAND.
 * @param gpu Pointer to the GPU device.
 */
void resetState(GpuDevice *gpu) {
    if (gpu->current_state == COMPLETED_TASK) {
        gpu->current_state = WAITING_FOR_COMMAND;
    }
}

/**
 * @brief Checks if the GPU is in a valid state.
 * @param gpu Pointer to the GPU device.
 * @return true if the GPU is in a valid state, false otherwise.
 */
bool isValidState(GpuDevice *gpu) {
    return gpu->current_state == WAITING_FOR_COMMAND ||
           gpu->current_state == PROCESSING_COMMAND ||
           gpu->current_state == EXECUTING_TASK ||
           gpu->current_state == COMPLETED_TASK;
}

