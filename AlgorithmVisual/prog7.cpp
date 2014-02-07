//@author Nathaniel Wendt
//@date April 2011
//@file Algorithm Visualization
//@description: This program shows the user how the Quicksort and Heapsort 
//              algorithm function

#include <iostream>
#include <fstream>
#include <string>

typedef int ItemType;
using namespace std;
const int MAXSIZE = 15;

//Define Text Colors
const string RED  = "\x1b[31m";
const string BLUE = "\x1b[34m";
const string YELLOW = "\x1b[33m";
const string GREEN = "\x1b[32m";
const string MAGENTA = "\x1b[35m";
const string BLACK = "\x1b[30m";
const string RESET = "\x1b[0m";
//End Text Colors

//@prints from a file until it detects the / character and stops
//@post the file entry is printed to the screen
//@usage printFromFile(infile);
void printFromFile(ifstream& infile);

//@prints the array while using labels and colors
//@pre the array is initialized with -1's where no values exist
//@param pivot - index of pivot
//@      lastl - index of lastless
//@      funk - index of first unknown
//@      first - starting index of array
//@      last - last index of array
//@usage printArray(items,pivot,2,5,0,6);
void printArray(ItemType items[], int pivot, int lastl, int funk, int first, int last);

//@prints an array with sections or labels
//@pre the array is initialized with -1's where no values exist
//@post the array is outputted
//@usage plainPrint(items);
void plainPrint(ItemType items[]);

//@prints a heap and allows for hiding certain values and showing labels
//@pre the array is initialized with -1's where no values exist
//@param items - array of items
//@      trickle - index of item to be outputted in green
//@      newswap - index of item to be outputted in magenta
//@      size - size of array to be printed - to hide values not applicable
//@usage heapPrint(myitems, trickle, newswap, 5);
void heapPrint(ItemType items[], int trickle, int newswap, int size);

//@swaps two values
//@pre the values are declared
//@post item1 has item2's value and vise versa
//@usage Swap(item1, item2);
void Swap(ItemType& item1, ItemType& item2);

//@partitions and array into an index and the left a less than or equal
//@to section and to the right a greater than section
//@pre the array has been initialized and the input stream initialized
//@post the array is partitioned and steps are outputted to the screen
//@param a - array of items
//@      first - first item
//@      last - last item
//@      pivotIndex - index of pivot
//@      input - input stream
//@usage Partition(items, 0, 5, 0, input);
void Partition(ItemType a[], int first, int last, int& pivotIndex,
                  ifstream& input);

//@sorts the array using the quicksort algorithm
//@pre items are declared and initialized
//@post the array is sorted and steps are outputted to screen
//@param a - array of items
//@      first - first item
//@      last - last item
//@      input - input stream
//@usage QuickSort(items, 0, 5, input);
void QuickSort(ItemType a[], int first, int last, ifstream& input);

//@rebuilder helper that rebuilds a heap
//@pre items are declared and initialized
//@post the array is in heap form
//@usage RebuildHeap(items, size, 0, input);
void RebuildHeap(ItemType items[], int msize, int root, ifstream& input);

//@sorts an array according to the heapsort algorithm
//@pre items are declared and initialized
//@post the array is sorted
//@usage HeapSort(items, input);
void HeapSort(ItemType items[], ifstream& input);

//@creates spacing and branches for neat output
//@post the correct spacing and labels are outputted
//@param level - current level of the tree
//@param tag - value of 1 if a right node
//@          - value of 2 if a left node
//@          - any other value if the node is a root
//@usage spacer(0, 2);
void spacer(int level, int tag);

//@displays the array in a computer science tree visual format
//@pre the array must be declared
//@post the array is prettily written to the screen in tree form
//@param level - level (starting at 0) of the tree
//@param tag - value of 1 if array item is a right child
//@          - value of 2 if array item is a left child
//@          - any other value if item is the root
//@usage writePretty(items, 0, 0, 0 , 1, 5, 2);
void writePretty (ItemType items[], int index, int size, int level, int tag,
                     int trickle, int newswap);

//@displays the array in a computer science tree visual format
//@post: outputs the array as in the example below
//
//                        bar
//                  foo
//                        geeU
//  root ->  queue
//                        stack
//                  list
//                        array
//@nodes at the same level are indented the same.
//@Viewer must rotate head 90 degrees in order to look like a cs tree
//@usage: prettyDisplay(items, trickle, newswap);
void prettyDisplay(ItemType items[], int trickle, int newswap);

//@opens the target exam data file
//@pre infile must be declared
//@post the infile stream is opened
//@param infile -- infile stream
//@usage openFile(infile)
void openFile(ifstream& file);

//@displays the Quicksort algorithm in a friendly manor
//@post the algorithm is shown on an array with steps
//@usage showQuickSort(input);
void showQuickSort(ifstream& input);

//@displays the HeapSort algorithm in a friendly manor
//@post the algorithm is shown on an array with steps
//@usage showHeapSort(input);
void showHeapSort(ifstream& input);

//@initializes the array to have -1 values instead of garbage
//@pre array is declared
//@post array is initialized with -1 values
//@usage initializeArray(items);
void initializeArray(ItemType items[]);

//@allows user to control the scroll of the screen
//@post accepts an enter key from the user
//@usage ToContinue();
void ToContinue();

int main()
{
   ifstream input;
   openFile(input);
   
   printFromFile(input);
   ToContinue();
   showQuickSort(input);
   ToContinue();
   showHeapSort(input);
   ToContinue();
   printFromFile(input);
   
}

//@allows user to control the scroll of the screen
//@post accepts an enter key from the user
//@usage ToContinue();
void ToContinue()
{
   char ch;
   cout << endl;
   cout << " -------- ^^   Steps Presented Above ^^    -----------" << endl;
   cout << " -------- ||   Hit <Enter> to continue ->  -----------" << endl;
   cin.get(ch);
   while(ch != '\n')
      cin.get(ch);
}

//@initializes the array to have -1 values instead of garbage
//@pre array is declared
//@post array is initialized with -1 values
//@usage initializeArray(items);
void initializeArray(ItemType items[])
{
   for(int i = 0; i < MAXSIZE; i++)
   {
      items[i] = -1;
   }
   items[0] = 5;
   items[1] = 4;
   items[2] = 6;
   items[3] = 1;
   items[4] = 7;
   items[5] = 9;
   items[6] = 2;
}

//@displays the Quicksort algorithm in a friendly manor
//@post the algorithm is shown on an array with steps
//@usage showQuickSort(input);
void showQuickSort(ifstream& input)
{
   ItemType items[MAXSIZE];
   printFromFile(input);   //intro message
   
   initializeArray(items);
   printFromFile(input);
   plainPrint(items);
   
   QuickSort(items, 0, 6, input);
   ToContinue();
   printFromFile(input);
   plainPrint(items);
}

//@displays the HeapSort algorithm in a friendly manor
//@post the algorithm is shown on an array with steps
//@usage showHeapSort(input);
void showHeapSort(ifstream& input)
{
   ItemType items2[MAXSIZE];
   printFromFile(input);  // intro message
   
   initializeArray(items2);
   HeapSort(items2, input);
   
   ToContinue();
   printFromFile(input);
   prettyDisplay(items2,0,0);
   heapPrint(items2,0,0,7);

}

//@prints from a file until it detects the / character and stops
//@post the file entry is printed to the screen
//@usage printFromFile(infile);
void printFromFile(ifstream& infile)
{
   string tempinput;
   int index = 0;
   getline(infile,tempinput);
   while(tempinput != "/")
   {
      cout << tempinput << endl;
      getline(infile,tempinput);
      index++;
   }
}

//@opens the target exam data file
//@pre infile must be declared
//@post the infile stream is opened
//@param infile -- infile stream
//@usage openFile(infile)
void openFile(ifstream& file)
{
    file.open("directions.dat");
    if (file.fail())
    {
        cout << "There was an error opening the data file " << endl;
        exit(1);
    }
}

//@sorts an array according to the heapsort algorithm
//@pre items are declared and initialized
//@post the array is sorted
//@usage HeapSort(items, input);
void HeapSort(ItemType items[], ifstream& input)
{
   int msize = 7;
   ItemType temp;
   
   for(int index = msize-1; index > 0; index--)
      RebuildHeap(items, msize, index, input);
     
   for(; msize > 0; msize--)
   {
      RebuildHeap(items, msize, 0, input);
            
      //output for user
      ToContinue();
      printFromFile(input);
      prettyDisplay(items,0,0);
      heapPrint(items,0,0,msize);
      
      if(msize > 1)
      {
         ToContinue();
         printFromFile(input);
         prettyDisplay(items,0,msize-1);
         heapPrint(items,0,msize-1,msize);
      }
  
      temp = items[0];
      items[0] = items[msize-1];
      items[msize-1] = temp;
   }
}

//@rebuilder helper that rebuilds a heap
//@pre items are declared and initialized
//@post the array is in heap form
//@usage RebuildHeap(items, size, 0, input);
void RebuildHeap(ItemType items[], int msize, int root, ifstream& input)
{
   int leftchild, rightchild, maxchild;
   leftchild = (2*root) + 1;
   if (leftchild < msize)
   {
      maxchild = leftchild;
      rightchild = leftchild + 1;
      if (rightchild < msize)
      {
         if(items[leftchild] > items[rightchild])
            maxchild = leftchild;
         else
            maxchild = rightchild;
      }
      if (items[root] < items[maxchild])
      {
         //output for user
         ToContinue();
         printFromFile(input);
         prettyDisplay(items,root,maxchild);
         heapPrint(items,root,maxchild,msize);
         
         Swap(items[root], items[maxchild]);
         RebuildHeap(items, msize, maxchild, input);
      }
   }
}

//@displays the array in a computer science tree visual format
//@post: outputs the array as in the example below
//
//                        bar
//                  foo
//                        geeU
//  root ->  queue
//                        stack
//                  list
//                        array
//@nodes at the same level are indented the same.
//@Viewer must rotate head 90 degrees in order to look like a cs tree
//@usage: prettyDisplay(items, trickle, newswap);
void prettyDisplay(ItemType items[], int trickle, int newswap)
{
   int size = 6;
   if (size == 0)
      cout << "EMPTY" << endl;
   else
   {   
      cout << "******  THE HEAP  ******" << endl;
      writePretty(items, 0, size, 0, 0, trickle, newswap);
   }
}

//@displays the array in a computer science tree visual format
//@pre the array must be declared
//@post the array is prettily written to the screen in tree form
//@param level - level (starting at 0) of the tree
//@param tag - value of 1 if array item is a right child
//@          - value of 2 if array item is a left child
//@          - any other value if item is the root
//@usage writePretty(items, 0, 0, 0 , 1, 5, 2);
void writePretty (ItemType items[], int index, int size, int level, int tag,
                       int trickle, int newswap)
{
   if (index <= size)
   {
      writePretty(items, 2*index + 2, size, level+1, 1, trickle, newswap);
      spacer(level, tag);
      if (trickle == newswap)
         cout << RESET;
      else if (trickle == index)
         cout << GREEN;
      else if (newswap == index)
         cout << MAGENTA;
      cout << items[index] << RESET << endl;
      writePretty(items, 2*index + 1, size, level+1, 2, trickle, newswap);
   }   
}

//@creates spacing and branches for neat output
//@post the correct spacing and labels are outputted
//@param level - current level of the tree
//@param tag - value of 1 if a right node
//@          - value of 2 if a left node
//@          - any other value if the node is a root
//@usage spacer(0, 2);
void spacer(int level, int tag)
{
   int space = 6*level;
   for (int i = 1; i < space; i++)
      cout << " ";
   if(tag == 1)
      cout << "/ ";
   else if (tag == 2)
      cout << "\\ ";
}

//@swaps two values
//@pre the values are declared
//@post item1 has item2's value and vise versa
//@usage Swap(item1, item2);
void Swap(ItemType& item1, ItemType& item2)
{
   ItemType temp;
   temp = item1;
   item1 = item2;
   item2 = temp;
}

//@sorts the array using the quicksort algorithm
//@pre items are declared and initialized
//@post the array is sorted and steps are outputted to screen
//@param a - array of items
//@      first - first item
//@      last - last item
//@      input - input stream
//@usage QuickSort(items, 0, 5, input);
void QuickSort(ItemType a[], int first, int last, ifstream& input)
{
   int pivotIndex;
   if (first < last)
   {
      Partition(a,first,last,pivotIndex, input);
      QuickSort(a,first,pivotIndex-1, input);
      QuickSort(a,pivotIndex+1,last, input);
   }
}

//@partitions and array into an index and the left a less than or equal
//@to section and to the right a greater than section
//@pre the array has been initialized and the input stream initialized
//@post the array is partitioned and steps are outputted to the screen
//@param a - array of items
//@      first - first item
//@      last - last item
//@      pivotIndex - index of pivot
//@      input - input stream
//@usage Partition(items, 0, 5, 0, input);
void Partition(ItemType a[], int first, int last, int& pivotIndex,
                  ifstream& input)
{
   ItemType pivot;
   int lastless, firstUnknown;
   
   pivot = a[first];
   firstUnknown = first+1;
   lastless = first;
   while( firstUnknown <= last)
   {
      // user output to show algorithm
      ToContinue();
      printFromFile(input);
      printArray(a,0,lastless,firstUnknown,first,last);
      //
      
      if(a[firstUnknown] <= pivot)
      {
         swap(a[firstUnknown],a[++lastless]);
      }
      firstUnknown++;
   }
   Swap(a[first],a[lastless]);
   pivotIndex = lastless;
   
   // user output to show algorithm
   ToContinue();
   printFromFile(input);
   printArray(a,pivotIndex,lastless,firstUnknown,first,last);
   //
   
   cout << endl;
}   

//@prints an array with sections or labels
//@pre the array is initialized with -1's where no values exist
//@post the array is outputted
//@usage plainPrint(items);
void plainPrint(ItemType items[])
{
   cout << endl << YELLOW;
   for(int i = 0; items[i] != -1; i++)
   {
      cout << i << "     ";
   }
   cout << endl;

   cout << RESET;
   for(int j = 0; items[j] != -1; j++)
   {
      cout << items[j] << "     ";
   }
   cout << endl << endl;
}

//@prints a heap and allows for hiding certain values and showing labels
//@pre the array is initialized with -1's where no values exist
//@param items - array of items
//@      trickle - index of item to be outputted in green
//@      newswap - index of item to be outputted in magenta
//@      size - size of array to be printed - to hide values not applicable
//@usage heapPrint(myitems, trickle, newswap, 5);
void heapPrint(ItemType items[], int trickle, int newswap, int size)
{
   cout << endl << YELLOW;
   for(int i = 0; items[i] != -1; i++)
   {
      cout << i << "     ";
   }
   cout << endl;

   cout << RESET;
   for(int j = 0; items[j] != -1; j++)
   {
      if (j >= size)
         cout << BLACK;
      else if (trickle == newswap)
         cout << RESET;   
      else if (j == trickle)
         cout << GREEN;
      else if (j == newswap)
         cout << MAGENTA;   
      cout << items[j] << "     " << RESET;
   }
   cout << endl << endl;
}

//@prints the array while using labels and colors
//@pre the array is initialized with -1's where no values exist
//@param pivot - index of pivot
//@      lastl - index of lastless
//@      funk - index of first unknown
//@      first - starting index of array
//@      last - last index of array
//@usage printArray(items,pivot,2,5,0,6);
void printArray(ItemType items[], int pivot, int lastl, int funk, int first, int last)
{
   int itemcount = 0;
   //first line
   cout << "    ";
   for(int i = first; (i <= last) && (items[i] != -1); i++)
   {
      itemcount++;
      cout << YELLOW << i << "     ";
   }
   cout << RESET << endl;
   //build markers
   int count = last-first;
   int pivotmarker;
   for(int i = 0; i < MAXSIZE && items[i] != -1; i++)
      count = count + 10;
   if(pivot == 0)
      pivotmarker = 4;
   else
      pivotmarker = (pivot*6) + 4 - first*6;   
   int lastmarker = (lastl*6) + 4 - first*6;
   int funkmarker = (funk*6) + 4 - first*6;  
   
   //second line
   int tempcount = 0;
   cout << "}   ";
   while (tempcount < itemcount)
   {
      cout << items[tempcount];
     // cout << endl << "lastless = " << lastl << endl;
     // cout << "pivot = " << pivot << endl;
     // cout << "funk = " << funk << endl;
      if(tempcount == pivot)
      {
         cout << RESET << "  |";
         if(lastl == pivot || (lastl > itemcount))
            cout << RED;
         else  
            cout << BLUE;
      }
      else if(tempcount == lastl)
      {
         cout << RESET << "  |";
         if(lastl + 1 != funk)
            cout << RED;
      }
      else if(tempcount == funk-1)
         cout << RESET << "  |" << RESET;
      else
         cout << "   ";
         

      if (pivot == 0 && lastl+1 == funk && pivot+1 != lastl)
         cout << RESET;    
        
          
      if(items[tempcount] > 9)
         cout << " ";
      else   
         cout << "  ";
      tempcount++;
   }
   cout << RESET << "{";
   cout << endl;
   
   //third line
   for (int j = 0; j < count; j++)
   {       
      if(j == pivotmarker || j == funkmarker || j == lastmarker)
         cout << "^";
      else
         cout << " ";
   }
   cout << endl;
   
   //third line
   for (int j = 0; j < count; j++)
   {
      if(j == pivotmarker || j == funkmarker || j == lastmarker)
         cout << "|";
      else
         cout << " ";
   }
   cout << endl;
   
   //third line
   for (int j = 0; j < count; j++)
   {
      if(j == pivotmarker)
         cout << "P";
      else if(j == funkmarker)
         cout << "U";
      else if(j == lastmarker)
      {
         cout << "LL";
         j++;
      }
      else
         cout << " ";
   }
   cout << endl;
   
}



