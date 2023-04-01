/*Write function bmi that calculates body mass index (bmi = weight / height2).

if bmi <= 18.5 return "Underweight"

if bmi <= 25.0 return "Normal"

if bmi <= 30.0 return "Overweight"

if bmi > 30 return "Obese"*/

const char *bmi (int weight, double height) {
    return (double)weight / (height * height) <= 18.5 ? "Underweight"
         : (double)weight / (height * height) <= 25 ? "Normal"
         : (double)weight / (height * height) <= 30 ? "Overweight"
         : "Obese";
}