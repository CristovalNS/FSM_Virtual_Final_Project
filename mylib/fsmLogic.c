
void calcNextState(int U_Select, int D_Select, int Floor_lvl, int Door_state, int nextState[2]){
  // State of the elevator door
  nextState[0] = ((!U_Select) & D_Select) | (U_Select & Door_state) | (U_Select & (!D_Select));
  // Floor of the elevator
  nextState[1] = (U_Select & (!D_Select) & Door_state) | (U_Select & Floor_lvl) | 
                 ((!D_Select) & Floor_lvl) | ((!Door_state) & Floor_lvl);
}

void calcOutput(int Floor_lvl, int Door_state, int output[4]){
  output[0] = !Floor_lvl; // !Q1 = First Floor -> 1st floor LED will light up
  output[1] = Floor_lvl; // Q1 = Second Floor -> 2nd floor LED will light up
  output[2] = !Door_state; // !Q0 = Door state -> Green LED will light up, signifying the doors are opened
  output[3] = Door_state; // Q0 = Door state -> Red LED will light up, signifying the doors are closed
}
