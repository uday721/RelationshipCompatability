# Intuit-Recruitment-Challenge

##How to Run the Program:
1. The program is written in visual c++ using visual studios 2015 IDE.
2. Clone or Download the project from github.
3. Open the solution in visual studios 2015 IDE and run the program.

---
##Inputs:

1. When you run the program a solution window pops up prompting to enter the two user names.
```
              Example : Enter the profile of first person:
```
2. Enter any two usernames from the transaction-data file to get their compatibility ratio.
```
              Example  :  Enter the profile of first person:user-1 (press Enter)
                  	      Enter the profile of second person:user-50 (press Enter)
```
---
##Output:

The output will be the compatibility ratio of the two users, the value will in the range of 0 to 1.

---
##Algorithm used for calculating compatibility:

1. The compatibility between two people is been calculated using only the data in "Vendor" and "Amount" column present in the transaction data file of a certain user.
2. There are 100 different vendors, each unique to certain number of users, so the total vendors are categorized into 15 main categories(Mint app is inspiration for this idea) like Education, Baby products, Marriage and Divorce etc.
3. The category file is included in the transaction-data folder of solution directory
4. Percentage of money spent by  a particular person on each category is calculated using his total expenditure.
5. Each category is given certain weightage and this weightage is calculated by number of transaction made in certain category by all users to total number of transaction of the users.
6. This weightage value can be obtained in a different manner as well, based on research done on relationships. I used the above method instead of giving arbitrary values.
7. According to some of the researches, people with same personalities and interests have better compatibility with each other like the saying “birds of same feather flock together”
8. So I calculated the difference in amount spent by two persons on their common interests based on the weightage of that category, for example user-1 spent 5% of his total expenditure on sports and similarly user-2 spent 7%, then I calculated the difference using the weightage.
9. The difference value is normalized using highest difference which is obtained by training data of all the users to every other user.
11. The obtained result from the above step is the difference between two people in their common interests, than (1-difference) should be the compatibility between them.
12. Even though many researches say that compatibility based on similar personalities and interests, I personally think that opposite might be possible as well like “unlike poles attract each other”.

---
Thank-you:
Uday shanker
b.udayshanker@outlook.com

  

