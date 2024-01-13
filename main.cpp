#include <iostream>
#include <string>
#include <stack>
#include <cstdlib>
#include <list>
#include <random>

using namespace std;

struct computation
{
    private:
        
    public:
        stack<string> path;
        int closestResult;

        computation()
        {

        }

};


//for each item of 6, create a branch.
class numberSolver
{
    //( int desiredResult, int arrayLength, int operatorIterationCount)
    private:

        //Constant values from default constructor
        int targetInteger;
        list<int> absoluteList;

        //Variables used for methods
        int closestIntegerReached = 0;
        string pathToNearestResult;
        stack<string> currentPath;
        computation nearestComputationToDestination;


    public:
        
        numberSolver(int inputTargetInteger, const list<int>& inputList)   :   targetInteger(inputTargetInteger), absoluteList(inputList)
        {
    
        }

        ////For every number: remove number from stack, pick another number and an operation to do, remove the other number from stack and pass stack and result into 4 new branches


        computation bruteForceResult()
        {
            bruteForceResultRecursion(0, absoluteList, stack<string> {});


            // //Test each integer gets a chance to start first?


                //Pass copy to recursion.

                // //Compare values to closest result so far, and update if needed

            // //Update the computation to the classes nearest results, and return it

            return nearestComputationToDestination;
        }

        void bruteForceResultRecursion(int inputValue, list<int> dynamicList, stack<string> startingPath) // TAKE FIRST ELEMENT, PERFORM OPERATION ON 2nd ELEMENT, UPDATE LIST TO HAVE NEITHER, PASS TO NEXT RECURSION
        {   
            //TESTING STUFF
            string testings;
            stack<string> relativePath;
            for ( auto& ittemp : dynamicList)
            {
                testings += to_string(ittemp);
                testings += ", ";   
            }

            int startingValue;
            int dynamicValue;
            
            //Make copy of list.
            list<int> copyList = dynamicList;
            

            //Iterate through list.
            int index = -1;
            for ( auto& it2 : copyList)
            {
                relativePath = startingPath;
                ++index;
                //Create copy without &it
                list<int> branchingList = copyList;
                list<int>::iterator removingIterator = branchingList.begin();
                advance(removingIterator, index);
                dynamicValue = it2;
                branchingList.erase(removingIterator);
                
                //Perform a computation with the two values, remove the value and pass remaining list to next recursion
            //ADDITION
                startingValue = inputValue;
                //cout << " Remaining int list: " << testings << "Value: " << to_string(startingValue += dynamicValue) << " (" << inputValue << " + " << dynamicValue << ") " << endl;;
                startingValue += dynamicValue;

                //Check if first integer in path stack

                if(startingPath.size() > 0) relativePath.push(" + " + to_string(dynamicValue));
                else relativePath.push(to_string(dynamicValue));

                //Check if its the closest value to desired result so far
                if (closerToTarget(startingValue))
                {
                    closestIntegerReached = startingValue;
                    nearestComputationToDestination.closestResult = startingValue;
                    nearestComputationToDestination.path = relativePath;
                }
                int listLength = branchingList.size();
                if (listLength !=0) bruteForceResultRecursion(startingValue, branchingList, relativePath);
                
                
                
                
                


                // //SUBTRACTION
                // startingValue = inputValue;
                // startingValue -= dynamicValue;
                // currentPath += (" - " + to_string(dynamicValue));
                // if (closerToTarget(startingValue))
                // {
                //     closestIntegerReached = startingValue;
                //     currentComputation.closestResult = startingValue;
                //     currentComputation.path = currentPath;
                // }
                // if (index != listLenght) bruteForceResultRecursion(startingValue, branchingList, currentPath);

            }
            
            
            // cout << "Closest value to " << to_string(targetInteger) << " found was: " << to_string(currentComputation.closestResult) << endl;
            // cout << "The path to this value was: " << currentComputation.path << endl << endl;


            
            

            



            
            

            // if (closerToTarget(DYNAMIC_RESULT))
            // {
            //     closestIntegerReached = DYNAMIC_RESULT;
            //     pathToNearestResult = DYNAMIC_PATH;
            // }



            
            
            // for (int i = 0; i < branchList.size(); i++)
            // {
            //     list<int>::iterator deletorIterator = copyList.begin();
            //     advance(deletorIterator,i);
                

            //     int value = *deletorIterator;
            //     copyList.erase(deletorIterator);
                
            //     cout << "branchList output: " << value << endl;

                


            //     // calculatedValue = startNumber + value;
            //     // newPath = path;
            //     // if (inputResult.closerResult(calculatedValue)) inputResult.setClosestResult(calculatedValue);
            //     // newPath += (" + " + to_string(value));
            //     // inputResult.setPath(newPath);
            //     // branch newBranch(calculatedValue, endingPoint, branchList, inputResult);
                

            //     // newPath = path;
            //     // calculatedValue = startNumber - value;
            //     // inputResult.closerResult(calculatedValue);
            //     // newPath += (" - " + to_string(value));
            //     // inputResult.setPath(newPath);
            //     // branch newBranch2(calculatedValue, endingPoint, branchList, inputResult);
            // }

            
            
           


            // for (int firstNumberIterator = 0; firstNumberIterator < arrayLength; firstNumberIterator++)
            // {
            //     //if (calculationResult == desiredResult) foundResult = true;

            //     if (abs(desiredResult-calculationResult) < abs(desiredResult-closestResult)
            //     || abs(desiredResult+calculationResult) < abs(desiredResult+closestResult))
            //     closestResult = calculationResult;

            //     calculationResult = firstNumberIterator;
                    
                

            // }
        }

        bool closerToTarget(int calculatedInteger)
        {
            // int test1 = abs(calculatedInteger - targetInteger);
            // int test2 = abs(closestIntegerReached - targetInteger);
            // bool test3 = test1 < test2;
            return ( (abs(calculatedInteger - targetInteger) < abs(closestIntegerReached - targetInteger)) );
        }

        string stackToStringConverter(stack<string> inputStack)
        {
            string s;
            stack<string> reverseOrder;
            while(!inputStack.empty())
            {
                reverseOrder.push(inputStack.top());
                inputStack.pop();
            }
            while(!reverseOrder.empty())
            {
                s+=reverseOrder.top();
                reverseOrder.pop();
            }
            return s;
        }





        //.
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
    cout << "Input Numbers: " << endl;
    for (int i = 0; i < arrayLength; i++)
    {
        
        cin >> numberArray[i];
    }

    int combinedAddition;
    // Display numbers
    cout << "List: ";
    for (int i = 0; i < arrayLength; i++)
    {
        cout << numberArray[i] << " ";
        if (i == 0)
        {
            combinedMultiple = numberArray[i];
            combinedAddition = numberArray[i];
        }
        else{
            //check for 1
        combinedMultiple = combinedMultiple * numberArray[i];
        combinedAddition += numberArray[i];
        }
    }

    ////Create target number
    // Calculate max value of arrays elements combined
    cout << "Max = " << combinedMultiple << endl;
    int maxValue;
    int minValue;
    // Calculate max value to be generated(multiply by 0.8)
    maxValue = combinedMultiple * 0.7;

    // Calculate min value to be generated(multiply by 0.1)
    minValue = combinedMultiple * 0.1;

    
    if (minValue == 0) minValue = 1;
    int targetInt = 0;
    
    minValue = numberOfInts;
    maxValue = combinedAddition;

    // Generate a number between minValue and maxValue
    random_device rd; // obtain a random number from hardware
    mt19937 gen(rd()); // seed the generator
    uniform_int_distribution<> distr(minValue, maxValue); // define the range
    targetInt = distr(gen);

    // while (targetInt < minValue || targetInt > maxValue)
    // {
    //     targetInt = rand();
    // }

    cout << "Target integer: " << targetInt << endl << endl; //<< " (between " << minValue << " and " << maxValue << ")" << endl;


    ////Recursively test combinations of smaller numbers and mathematical operations till you get as close to result as possible
    //Write out ruleset
        //Each smaller number can only be used once
        //Limited to mathematical operations of addition, subtraction, multiplication and division
        //This means a maximum of 5 operations for a full test
    


    //Methods to finding the closest number
    //Hopefully try code all?
        //Option 1 (Easy + Dirty) Brute force every combination
        //Option 2 (Complex probably) Use results of each operation to determine where to operate next?
        //Option 3 (Lots of hardcoding probably) Vary implementation based on numbers? 
        //If you have easy derivations such as aiming for a multiple of 10, then aim to make something that divises into it cleanly?

    bool foundResult = false;
    int calculationResult = 0;
    int closestResultValue = 0;

    list<int> numberList(begin(numberArray), end(numberArray)); 
    string inputString;

    //Pass in: Target integer, list of numbers
    //Return: Result and path to it

    numberSolver bruteForce(targetInt, numberList);
    computation getResult = bruteForce.bruteForceResult();
    
    cout << "Actual number aimed for: " << targetInt << endl;
    cout << "Result reached: " << getResult.closestResult << endl;
    cout << "Path to result: " << bruteForce.stackToStringConverter(getResult.path) << endl;
    

        
    

}
















