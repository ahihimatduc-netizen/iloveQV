#include <stdio.h> 
#include <string.h>
int main() {
    // Declare float variables to store weight, height, and BMI
    float weight, height, bmi;
    char name[50]; //Add array to store user name

    // --- STEP 1: INPUT DATA ---
    printf("Enter your name:");
    fflush(stdin);
    fgets(name,sizeof (name),stdin);
    name[strcspn(name,"\n")]='\0';

    printf("Enter your weight (kg):");
    scanf("%f", &weight); // Read weight from user input and assign it to the 'weight' variable

    printf("Enter your height (m): ");
    scanf("%f", &height); // Read height from user input and assign it to the 'height' variable

    // --- STEP 2: DATA VALIDATION ---
    // Height and weight must be positive numbers (> 0). If invalid, print an error and exit.
    if (height <= 0 || weight <= 0) {
        printf("ERROR: Height and weight must be higher than 0!\n");
        return 1; // Return 1 to indicate the program ended due to an error
    }

    // --- STEP 3: CALCULATE BMI ---
    // BMI Formula = Weight (kg) / (Height (m) * Height (m))
    bmi = weight / (height * height);

    // --- STEP 4: PRINT RESULTS AND ASSESSMENT ---
    printf("\n--- Result---\n");
    // Print the BMI value rounded to 2 decimal places (%.2f)
    printf("Chi so BMI cua ban la: %.2f\n", bmi); 
    printf("Your health condition: ");

    // If-else structure to classify health condition based on the BMI value
    if (bmi < 18.5) {
        // Classification: Underweight
        printf("Underweight\n");
        printf("\n=> Suggestion:\n");
        printf("- Nutrition: Increase calorie intake from healthy foods (lean meat, fish, eggs, milk, nuts). Eat more snacks throughout the day.\n");
        printf("- Exercise: Combine physical training (gym, calisthenics) to increase muscle mass instead of just increasing fat.\n");
    } 
    else if (bmi < 25) {
        // Classification: Normal weight (from 18.5 to 24.9)
        printf("Normal (healthy)\n");
        printf("\n=> Suggestion:\n");
        printf("-Great! Keep maintaining your current balanced diet and active lifestyle to stay healthy.\n");
    } 
    else if (bmi < 30) {
        // Classification: Overweight (from 25 to 29.9)
        printf("Overweight\n");
        printf("- Potential Diseases: Increased risk of Pre-diabetes (insulin resistance), Dyslipidemia (high cholesterol/triglycerides), and early-stage Fatty Liver.");
        printf("\n=> Suggestion: \n");
        printf("- Nutrition: Focus on crowding out processed foods. Instead of strict restriction, prioritize high-protein meals and fiber (vegetables/whole grains) to increase satiety. Small changes, like switching from sugary drinks to water or black coffee, often yield the best long-term results.");
        printf("- Exercise: Focus on a mix of Resistance Training (weightlifting) to build muscle mass and Cardio (running, swimming, or sports like badminton) to improve heart health. Building muscle is crucial here because it raises your resting metabolic rate.");
    }
    else if (bmi < 35) {
        // Classification: Obesity class I (from 30 to 34.9)
        printf("Obesity class I\n");
        printf("- Potential Diseases: Increased risk of Pre-diabetes (insulin resistance), Dyslipidemia (high cholesterol/triglycerides), and early-stage Fatty Liver.");
        printf("\n=> Suggestion:\n");
        printf("- Nutrition: Reduce your intake of refined sugar, fast food, and refined carbohydrates. Increase your consumption of vegetables and drink more water.\n");
        printf("- Exercise: Dedicate at least 30-45 minutes each day to cardio exercises (running, cycling, swimming) to burn excess calories.\n");
    } 
    else if (bmi < 40){
        // Classification: Obesity class II (from 35 to 39.9)
        printf ("Obesity class II\n");
        printf("- Potential Diseases: Increased risk of Pre-diabetes (insulin resistance), Dyslipidemia (high cholesterol/triglycerides), and early-stage Fatty Liver.");
        printf ("\n=> Suggestion:\n");
        printf ("- Nutrition: Focus on portion control and rather than skipping. Replace refined sugars and white flours with high-fiber whole grains and lean proteins.\n");
        printf ("-Exercise: Focus on swimming, walking, and chair squats while avoiding jumping to protect joints and improve your overall physical fitness levels.\n");
    }
    else {
        // Classification: Obesity class III (BMI >= 40)
        printf ("Obesity class III\n");
        printf("- Potential Diseases: Increased risk of Pre-diabetes (insulin resistance), Dyslipidemia (high cholesterol/triglycerides), and early-stage Fatty Liver.");
        printf ("\n=> Suggestion");
        printf ("Consulting a doctor immediately, adopting a structured reduced-calorie diet, increasing physical activity, and exploring medical options like weight-loss medications or bariatric surgery if necessary.");
    }
    // Create a file
    FILE *file = fopen("bmi_database.txt","a");
    // Check if the file opens successfully
    if (file == NULL) {
        printf("Error: Can not open file to save data");
        return 1;
    }
     // save the data to a file
     fprintf (file,"Name: %s | Weight: %.2f (kg) | Height: %.2f (m) | BMI: %.2f \n",name, weight,height,bmi);
     //Close file
    fclose(file);
    printf("\n Your data has been saved");
    printf("\n---------------\n");

    return 0; // Return 0 to indicate successful execution
}