# Plant Monitoring
## _ARDUINO project_

## Objectives 
- Development of a system that supervises the evolution of house plants
- Usage of light, temperature and soil humidity sensors

## Implementation

The project is based on hardware design as well as software. In a 30min interval, the light intensity, temperature and soil moisture levels will be measured, using the corresponding sensors. The code then will compare the results with the optimal levels that would provide the safe growth of the plant. If the results are not within the safety range, the LED will light up and the LCD screen will display the issue at hand.

The safe values chosen for the parameters are were selected from  https://www.aquagardening.com.au/learn/ideal-temperature-and-light-for-plants/i and https://www.acurite.com/gdpr

### Logical block diagram
![plant_monitoring_diagram](https://github.com/andreeadiaconu55/Plant-Monitoring/assets/132846833/91241b81-2402-4037-be81-d537fbc4e23c)

### Hardware
# Bill of materials

| Material | Model |
| ------ | ------ |
| Microcontroller | Arduino UNO R3 |
| Temperature sensor | DHT11 with LED |
| Ligt sensor | Photoresistor Module |
| Soil humidity sensor | Capacitative Soil Moisture Sensor v2.0 |
| Resistences | 220Ohms |
| Breadboard | HQ830 |
| LCD Screen | LCD 1602 I2C Interface Backlight Yellow-Green |
| LED light |
### Software
The code for the Arduino Microcontroller will be attached in the repository. 

### Montage
![plant_monitoring1](https://github.com/andreeadiaconu55/Plant-Monitoring/assets/132846833/8a945eb3-6db5-4c34-9eaa-adfcded78c09)
![plant_monitoring2](https://github.com/andreeadiaconu55/Plant-Monitoring/assets/132846833/5f478acf-6df1-49a2-99c5-6d0f1cdb5953)

### Demo


https://github.com/andreeadiaconu55/Plant-Monitoring/assets/132846833/d10984d8-f5f8-4928-a591-041ab281e90a

