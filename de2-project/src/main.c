
// includes

// end includes

int main (void){

// inicializace pinů a globálních proměnných
int soil_humidity = get_soil_humidytiy();
int air_humidity = get_air_humidity();
int air_temp = get_air_temp();
int tank_level = get_tank_level(); // in %
int room_light = get_room_light(); 
int lamp_intenzity = 0;

bool pump_state = false;
bool low_water_level = false; 
bool bad_temp = false;


while(1){
// tady bude všechna magie

  
}


return 0;
}