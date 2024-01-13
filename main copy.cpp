#include <iostream>
#include <string>
#include <cstdlib>
#include <list>

using namespace std;

struct result
{
    private:
        string path;
        int closestResult;
        int recquiredResult;
        bool resultFound;
    
    public:
        result(){}
        result(string inputPath, int inputClosestResult)
        {
            path = inputPath;
            closestResult = inputClosestResult;
        }

        string getPath() {return path;}
        void setPath(string inputPath) {path = inputPath;}

        int getClosestResult() {return closestResult;}
        void setClosestResult(int inputResult) {closestResult = inputResult;}

        int getRecquiredResult() {return recquiredResult;}
        void setRecquiredResult(int inputResult) {recquiredResult = inputResult;}

        bool getResultFound() {return resultFound;}
        void setResultFound(bool inputBool) {resultFound = inputBool;}

        bool closerResult(int inputInteger)
        {
            if (abs(recquiredResult-inputInteger) < abs(recquiredResult-closestResult)
            || abs(recquiredResult+inputInteger) < abs(recquiredResult+closestResult))
                closestResult = inputInteger;
        }
};


//for each item of 6, create a branch.
class branch
{
    //( int desiredResult, int arrayLength, int operatorIterationCount)
    private:
        int startNumber;
        int endingPoint;
        list<int> branchList;
        result branchResult;


    public:
        
        branch(int inputStartingPoint, int inputEndingPoint, const list<int>& inputList, result inputResult):startNumber(inputStartingPoint), branchList(inputList),
         branchResult(inputResult), endingPoint(inputEndingPoint)
        {
        }

        ////For every number: remove number from stack, pick another number and an operation to do, remove the other number from stack and pass stack and result into 4 new branches






        result calculateResult() 
        {
            int closestResultInt;
            int calculatedValue;

            result inputResult;
            string path = branchResult.getPath();
            string newPath;
            closestResultInt = branchResult.getClosestResult();

            list<int> copyList = branchList;
            for (int i = 0; i < branchList.size(); i++)
            {
                list<int>::iterator deletorIterator = copyList.begin();
                advance(deletorIterator,i);
                

                int value = *deletorIterator;
                copyList.erase(deletorIterator);
                
                cout << "branchList output: " << value << endl;

                


                calculatedValue = startNumber + value;
                newPath = path;
                if (inputResult.closerResult(calculatedValue)) inputResult.setClosestResult(calculatedValue);
                newPath += (" + " + to_string(value));
                inputResult.setPath(newPath);
                branch newBranch(calculatedValue, endingPoint, branchList, inputResult);
                

                newPath = path;
                calculatedValue = startNumber - value;
                inputResult.closerResult(calculatedValue);
                newPath += (" - " + to_string(value));
                inputResult.setPath(newPath);
                branch newBranch2(calculatedValue, endingPoint, branchList, inputResult);

                newPath = path;
                calculatedValue = startNumber * value;
                inputResult.closerResult(calculatedValue);
                newPath += (" * " + to_string(value));
                inputResult.setPath(newPath);
                branch newBranch3(calculatedValue, endingPoint, branchList, inputResult);

                newPath = path;
                calculatedValue = startNumber / value;
                inputResult.closerResult(calculatedValue);
                newPath += (" / " + to_string(value));
                inputResult.setPath(newPath);
                branch newBranch4(calculatedValue, endingPoint, branchList, inputResult);
            }

            
            
            return inputResult;


            // for (int firstNumberIterator = 0; firstNumberIterator < arrayLength; firstNumberIterator++)
            // {
            //     //if (calculationResult == desiredResult) foundResult = true;

            //     if (abs(desiredResult-calculationResult) < abs(desiredResult-closestResult)
            //     || abs(desiredResult+calculationResult) < abs(desiredResult+closestResult))
            //     closestResult = calculationResult;

            //     calculationResult = firstNumberIterator;
                    
                

            // }
        }
};


int main ()
{
    ////Generate and store 6 numbers
    // Create consts and storage
    const int numberOfInts = 6;
    int combinedMultiple;

    static int numberArray[numberOfInts];
    int arrayLength = sizeof(numberArray)/sizeof(numberArray[0]);

    // Create numbers
    for (int i = 0; i < arrayLength; i++)
    {
        cout << "Input Num: " << endl;
        cin >> numberArray[i];
    }

    // Display numbers
    cout << "List: ";
    for (int i = 0; i < arrayLength; i++)
    {
        cout << numberArray[i] << " ";
        if (i == 0)
        {
            combinedMultiple = numberArray[i];
        }
        else{
            //check for 1
        combinedMultiple = combinedMultiple * numberArray[i];
        }
    }

    ////Create target number
    // Calculate max value of arrays elements combined
    cout << "Max = " << combinedMultiple << endl;
    int maxValue;
    int minValue;
    // Calculate max value to be generated(multiply by 0.8)
    maxValue = combinedMultiple * 0.8;

    // Calculate min value to be generated(multiply by 0.1)
    minValue = combinedMultiple * 0.1;
    if (minValue == 0) minValue = 1;
    int randInt = 0;

    // Generate a number between minValue and maxValue
    while (randInt < minValue || randInt > maxValue)
    {
        randInt = rand();
    }

    cout << "Target integer: " << randInt << " (between " << minValue << " and " << maxValue << ")" << endl;


    ////Recursively test combinations of smaller numbers and mathematical operations till you get as close to result as possible
    //Write out ruleset
        //Each smaller number can only be used once
        //Limited to mathematical operations of addition, subtraction, multiplication and division
        //This means a maximum of 5 operations for a full test
    


    //Methods to finding the closest number
        //Option 1 (Easy + Dirty) Brute force every combination
    bool foundResult = false;
    int calculationResult = 0;
    int closestResultValue = 0;

    list<int> numberList(begin(numberArray), end(numberArray)); 
    result getResult;
    string inputString;
    

    for (int i = 0; i < arrayLength; i++)
    {
        //Save the value at location i into the result object
        inputString = "Starting from: (";
        inputString += to_string(numberArray[i]);
        inputString += ")";
        getResult.setPath(inputString);

        //Create iterator to remove the value from the list
        auto listIterator = numberList.begin();
        advance(listIterator, i);
        numberList.erase(listIterator);

        //Pass in starting value, and the remainder of the list
        branch newBranch(numberArray[i], randInt, numberList, getResult);
        getResult = newBranch.calculateResult();
    }
    

        //Option 2 (Complex probably) Use results of each operation to determine where to operate next?
        //Example Data: Make 250 from 5, 6, 10, 21, 3. 


        //Option 3 (Lots of hardcoding probably) Vary implementation based on numbers? 
        //If you have easy derivations such as aiming for a multiple of 10, then aim to make something that divises into it cleanly?
    

}
















