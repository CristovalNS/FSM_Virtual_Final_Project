#include <stdio.h>
#include "mylib/fsmLogic.h"
#include <string.h>

int main(void) {
  int U_Select, D_Select, Door_state;
  int nextState[2], output[4];
  char quit[10]; // Variable to store 'quit'
  int Floor_lvl;

  printf("--------------------------------------------------\n");
  printf("This is a simple Elevator FSM implemented in C language\n");
  printf("Made by: Cristoval Neo Sasono_2602158235\n");
  printf("--------------------------------------------------\n");

  printf("Before starting this simulation, please enter the starting floor level. \n");
  printf("Floor Level([0] = 1st Floor | [1] = 2nd Floor): ");
  scanf("%d", &Floor_lvl); // get initial value of Floor_lvl
  if (Floor_lvl == 0){
    printf("Starting Floor: [1st Floor]\n");
  } 
  else if (Floor_lvl == 1){
    printf("Starting Floor: [2nd Floor]\n");
  }

  while (1){
  printf("--------------------------------------------------\n");
  printf("Starting elevator simulation.\n");
  printf("--------------------------------------------------\n");


  // User input values
  printf("UP Button ([0] = NO INPUT | [1] = SELECT): ");
    scanf("%d", &U_Select);
    if (U_Select == 1){
      printf("Selected: [UP Button]\n");
    }

    printf("--------------------------------------------------\n");

    printf("DOWN Button ([0] = NO INPUT | [1] = SELECT): ");
    scanf("%d", &D_Select);
    if (D_Select == 1){
      printf("Selected: [DOWN Button]\n");
    }

    printf("--------------------------------------------------\n");

    printf("Door State ([0] = OPEN | [1] = CLOSED): ");
    scanf("%d", &Door_state);
    if (Door_state == 0){
      printf("Door State: [OPEN]\n");
    } 
    else if (Door_state == 1){
      printf("Door State: [CLOSED]\n");
    }

    printf("--------------------------------------------------\n");

    // Calculate next state
    calcNextState(U_Select, D_Select, Floor_lvl, Door_state, nextState);
    printf("Next state: %d %d\n", nextState[1], nextState[0]);

    // Calculate output
    calcOutput(Floor_lvl, Door_state, output);
    printf("LED Output BEFORE: %d %d %d %d\n", output[0], output[1], output[2], output[3]);

  printf("--------------------------------------------------\n");

  if (Floor_lvl == 0 && Door_state == 0) {
    // 1st Floor - Door Open(0 0)
    printf("Visualization of Elevator State BEFORE: \n");
    printf("|_____________|\n");
    printf("|  2nd Floor  |\n");
    printf("|             |\n");
    printf("|             |\n");
    printf("|             |\n");
    printf("|             |\n");
    printf("|             |\n");
    printf("|             |\n");
    printf("|=============|\n");
    printf(" _____________ \n");
    printf("|  1st Floor  |\n");
    printf("||           ||\n");
    printf("||           ||\n");
    printf("||           ||\n");
    printf("||           ||\n");
    printf("||           ||\n");
    printf("|  Door Open  |\n");
    printf("|_____________|\n");
    printf("LED Light Indicators: \n");
    printf("\033[33m[1]\033[0m[2]\033[32m[O]\033[0m[X]\n\n");
    printf("");
  }
  if (Floor_lvl == 0 && Door_state == 1) {
    // 1st Floor - Door Closed(0 1)
    printf("Visualization of Elevator State BEFORE: \n");
    printf("|_____________|\n");
    printf("|  2nd Floor  |\n");
    printf("|             |\n");
    printf("|             |\n");
    printf("|             |\n");
    printf("|             |\n");
    printf("|             |\n");
    printf("|             |\n");
    printf("|=============|\n");
    printf(" _____________ \n");
    printf("|  1st Floor  |\n");
    printf("|   __   __   |\n");
    printf("|  |  | |  |  |\n");
    printf("|  |  | |  |  |\n");
    printf("|  |  | |  |  |\n");
    printf("|  |__| |__|  |\n");
    printf("| Door Closed |\n");
    printf("|_____________|\n");
    printf("LED Light Indicators: \n");
    printf("\033[33m[1]\033[0m[2][O]\033[31m[X]\033[0m\n\n");
    printf("");
  }
  if (Floor_lvl == 1 && Door_state == 0) {
    // 2nd Floor - Door Open(1 0)
    printf("Visualization of Elevator State BEFORE: \n");
    printf(" _____________ \n");
    printf("|  2nd Floor  |\n");
    printf("||           ||\n");
    printf("||           ||\n");
    printf("||           ||\n");
    printf("||           ||\n");
    printf("||           ||\n");
    printf("|  Door Open  |\n");
    printf("|_____________|\n");
    printf("|             |\n");
    printf("|=============|\n");
    printf("|  1st Floor  |\n");
    printf("|             |\n");
    printf("|             |\n");
    printf("|             |\n");
    printf("|             |\n");
    printf("|             |\n");
    printf("|_____________|\n");
    printf("LED Light Indicators: \n");
    printf("[1]\033[33m[2]\033[0m\033[32m[O]\033[0m[X]\n\n");
    printf("");
  }
  if (Floor_lvl == 1 && Door_state == 1) {
    // 2nd Floor - Door Closed(1 1)
    printf("Visualization of Elevator State BEFORE: \n");
    printf(" _____________ \n");
    printf("|  2nd Floor  |\n");
    printf("|   __   __   |\n");
    printf("|  |  | |  |  |\n");
    printf("|  |  | |  |  |\n");
    printf("|  |  | |  |  |\n");
    printf("|  |__| |__|  |\n");
    printf("| Door Closed |\n");
    printf("|_____________|\n");
    printf("|             |\n");
    printf("|=============|\n");
    printf("|  1st Floor  |\n");
    printf("|             |\n");
    printf("|             |\n");
    printf("|             |\n");
    printf("|             |\n");
    printf("|             |\n");
    printf("|_____________|\n");
    printf("LED Light Indicators: \n");
    printf("[1]\033[33m[2]\033[0m[O]\033[31m[X]\033[0m\n\n");
    printf("");
  }

  if (U_Select == 0 && D_Select == 0 && nextState[1] == 0 && nextState[0] == 0 || 
      U_Select == 0 && D_Select == 0 && nextState[1] == 0 && nextState[0] == 0 || 
      U_Select == 1 && D_Select == 1 && nextState[1] == 0 && nextState[0] == 0 ) {
    // 1st Floor - Door Opened (0 0)
    printf("Visualization of Elevator State AFTER: \n");
    printf("|_____________|\n");
    printf("|  2nd Floor  |\n");
    printf("|             |\n");
    printf("|             |\n");
    printf("|             |\n");
    printf("|             |\n");
    printf("|             |\n");
    printf("|             |\n");
    printf("|=============|\n");
    printf(" _____________ \n");
    printf("|  1st Floor  |\n");
    printf("||           ||\n");
    printf("||           ||\n");
    printf("||           ||\n");
    printf("||           ||\n");
    printf("||           ||\n");
    printf("|  Door Open  |\n");
    printf("|_____________|\n");
    printf("LED Light Indicators: \n");
    printf("\033[33m[1]\033[0m[2]\033[32m[O]\033[0m[X]\n");
  }
  if (U_Select == 0 && D_Select == 0 && nextState[1] == 1 && nextState[0] == 0 ||
      U_Select == 0 && D_Select == 0 && nextState[1] == 1 && nextState[0] == 0 ||
      U_Select == 1 && D_Select == 1 && nextState[1] == 1 && nextState[0] == 0 ) {
    // 2nd Floor - Door Opened (1 0)
    printf("Visualization of Elevator State AFTER: \n");
    printf(" _____________ \n");
    printf("|  2nd Floor  |\n");
    printf("||           ||\n");
    printf("||           ||\n");
    printf("||           ||\n");
    printf("||           ||\n");
    printf("||           ||\n");
    printf("|  Door Open  |\n");
    printf("|_____________|\n");
    printf("|             |\n");
    printf("|=============|\n");
    printf("|  1st Floor  |\n");
    printf("|             |\n");
    printf("|             |\n");
    printf("|             |\n");
    printf("|             |\n");
    printf("|             |\n");
    printf("|_____________|\n");
    printf("LED Light Indicators: \n");
    printf("[1]\033[33m[2]\033[0m\033[32m[O]\033[0m[X]\n");
  }
  if (U_Select == 0 && D_Select == 1 && nextState[1] == 0 && nextState[0] == 1 ||
      U_Select == 0 && D_Select == 1 && nextState[1] == 0 && nextState[0] == 1 ||
      // U_Select == 0 && D_Select == 1 && nextState[1] == 1 && nextState[0] == 1 ||
      U_Select == 1 && D_Select == 0 && nextState[1] == 0 && nextState[0] == 1 ||
      U_Select == 1 && D_Select == 1 && nextState[1] == 0 && nextState[0] == 1 ) {
    // 1st Floor - Door Closed (0 1)
    printf("Visualization of Elevator State AFTER: \n");
    printf("|_____________|\n");
    printf("|  2nd Floor  |\n");
    printf("|             |\n");
    printf("|             |\n");
    printf("|             |\n");
    printf("|             |\n");
    printf("|             |\n");
    printf("|             |\n");
    printf("|=============|\n");
    printf(" _____________ \n");
    printf("|  1st Floor  |\n");
    printf("|   __   __   |\n");
    printf("|  |  | |  |  |\n");
    printf("|  |  | |  |  |\n");
    printf("|  |  | |  |  |\n");
    printf("|  |__| |__|  |\n");
    printf("| Door Closed |\n");
    printf("|_____________|\n");
    printf("LED Light Indicators: \n");
    printf("\033[33m[1]\033[0m[2][O]\033[31m[X]\033[0m\n");
  }
  if (U_Select == 0 && D_Select == 1 && nextState[1] == 1 && nextState[0] == 1 ||
      // U_Select == 1 && D_Select == 0 && nextState[1] == 0 && nextState[0] == 1 ||
      U_Select == 1 && D_Select == 0 && nextState[1] == 1 && nextState[0] == 1 ||
      U_Select == 1 && D_Select == 0 && nextState[1] == 1 && nextState[0] == 1 ||
      U_Select == 1 && D_Select == 1 && nextState[1] == 1 && nextState[0] == 1 ) {
    // 2nd Floor - Door Closed (1 1)
    printf("Visualization of Elevator State AFTER: \n");
    printf(" _____________ \n");
    printf("|  2nd Floor  |\n");
    printf("|   __   __   |\n");
    printf("|  |  | |  |  |\n");
    printf("|  |  | |  |  |\n");
    printf("|  |  | |  |  |\n");
    printf("|  |__| |__|  |\n");
    printf("| Door Closed |\n");
    printf("|_____________|\n");
    printf("|             |\n");
    printf("|=============|\n");
    printf("|  1st Floor  |\n");
    printf("|             |\n");
    printf("|             |\n");
    printf("|             |\n");
    printf("|             |\n");
    printf("|             |\n");
    printf("|_____________|\n");
    printf("LED Light Indicators: \n");
    printf("[1]\033[33m[2]\033[0m[O]\033[31m[X]\033[0m\n");
  }

  printf("--------------------------------------------------\n");
  
    Floor_lvl = nextState[1];
  //Test [Comment when done]: To see the updated value of Floor_lvl with the value of nextState[1]
    // printf("Floor Level([0] = 1st Floor | [1] = 2nd Floor): \n");
    // printf("Current Floor lvl: %d\n", Floor_lvl);

  printf("Enter anything to continue the simulation. Otherwise, enter 'quit': ");
    scanf("%s", quit);
    if (strcmp(quit, "quit") == 0) {
      printf("Thank you for using my elevator simulation ^-^");
      break; // exit the loop
    }
  }
  return 0;
}

