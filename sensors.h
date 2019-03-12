
#define ENABLE_BMP280
#define ENABLE_BH1750
#define ENABLE_SSD1306
#define ENABLE_DHT22
#define ENABLE_ANALOG

#define MEAN_SEA_LEVEL_PRESSURE 1013.25

#define DHT22_GPIO_PIN      14

//
// Sensor initialisation and reading routines. 
//

extern void init_DHT22();
extern int read_DHT22(float* temp_p, float* hum_p);

extern void init_BH1750();
extern int read_BH1750(int& lux_p);

extern void init_BMP280();
extern int read_BMP280(float* temp_p, float* pres_p, float* alt_p);
