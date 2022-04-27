# watchRepairDateEstimator
### Estimation of Wrist Watch repair delivery date
## **Description:**  
### This program calculates the pickup date for customers of a branded watch repair shop based on 
* vailability of parts for a particular model
* considering the workload, working hours,
* time required to repair each component of a particular model
* holidays/leaves taken by the mechanic
### and stores the data in **JSON files** so that the data can be easily accessed by App & Web developers.
### All the issues are identified during admission of a watch during Admission. Based on model number of a watch it is possible to find out part number of it's components, the program will check it's logs (files) to see if required components are in stock and based on requirements decrement the count of each required part. If a part is un available it should display the Contact details of the supplier. Finally the program will consider the agenda of the mechanic and the final output of the program will be a date, the delivery date.
## **Instructions**
1. Run FileGenerator.c
1. Check the files created
1. Run AppSourceCode.c
1. ATTENTION!!! note that any incorrect data entry will probably corrupt few or all files created after step 1.
1. To verify the results check the files by opening the JSON files generated during step 1 and run BinaryFileDataVerifier.c to view the binary file log.
1. Hurray! The program has been successfuly executed. The updated files are now ready to be used in complex Applications

### Feel free to leave any suggestions 😊✨✨✨
