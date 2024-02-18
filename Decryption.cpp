#include<bits/stdc++.h>
using namespace std;


// This function performs an anticlockwise rotation on a string array.
// arr is the input array to be rotated.
// size is the size of the array.
// rotations is the number of positions to rotate the array.
// It uses a temporary array temp to store the original values.
// It then calculates the new index after the rotation and updates the original array.
static void rotateAnticlockwise(string arr[], int size, int rotations) {
    string temp[size];

    for (int i = 0; i < size; i++) {
        temp[i] = arr[i];
    }

    for (int i = 0; i < size; i++) {
        arr[(i - rotations + size) % size] = temp[i];
    }
}


// This function takes a string st and a map apl.
// For each character in st, it finds the corresponding string in the map apl and appends it to the result string s.
static string change(string st ,map<char ,string>& apl)
{
    string s;
    for(int i=0;i<st.length();i++)
    {
        char ch=st.at(i);
        string conf;
        auto pk=apl.find(ch);
        conf = pk->second;
        s+=conf;
    }
    return s;
}


// This function calculates a random position based on the ASCII values of characters in the input string dp.
// It sums the ASCII values, takes the modulus of the product of the length of dp and 2, and returns the result.
static int randomPosition(string dp)
{
    int a=0;
    for(int i=0;i<dp.length();i++)
    {
       a+=(int)dp.at(i);
    }
    a=a%(dp.length()*2);
    return a;
}


// This function rotates a character array arr by k positions.
// It uses a temporary array temp to store the last k characters of the original array.
// It then shifts the remaining characters to the right and copies the temporary array back to the beginning.
static void rotateArray(char arr[], int n, int k) {

    char temp[k];
    for (int i = 0; i < k; i++) {
        temp[i] = arr[n - k + i];
    }

    for (int i = n - 1; i >= k; i--) {
        arr[i] = arr[i - k];
    }

    for (int i = 0; i < k; i++) {
        arr[i] = temp[i];
    }
}


int main()
{
    
  // ... (variable declarations and file reading)
   ifstream file;
  string filename="filename.txt";
  
  int line_number=4; //Used to determine line 4 of the file to read the encrypted words
  
  if (line_number <= 0)
  {
    cout << "Line number must be >= 1" << endl;
    return 1;
  }
  
  file.open(filename);
  
  if (file.fail())
  {
    cout << "File failed to open." << endl;
    return 1;
  }

  // initializing current_line to 0.
  int current_line = 0;
  string line;


  // Loop through lines in the file
  // The code then enters a loop that reads lines from the file specified by the filename variable. 
  // It continues reading lines until it reaches the specified line number (line_number), incrementing current_line with each iteration. 
  // If the line is found, it breaks out of the loop.
  while (current_line<6)
  {
    current_line++;
    getline(file, line);
    if (current_line == line_number) break;
  }
  if (current_line < line_number)
  {
    cout << "Line not found!" << endl;
    cout << "File contains " << current_line;
    cout << " lines total." << endl;
  }

     // ... (further variable declarations)
     char messagechar[54] = {'a','f','g','F','H','p','C','r','T','h','w','S','x','z','K','l','Q','o','N','b','A','J','.','D','i','d','W','v','G','y','E','P','Y','O','M','L','U','Z','u','X','j','e','c','s','q','B','I','t','n','R','m',' ','V','k'};
     char charcater[54] = {'D','f','s','W','E','e','V','r','T','t','Y','.','U','z','I','l','i','o','P','b','A','J','S','a','Q','d','F','q','G','y','H','N','w','j','M','L','x','Z','u','X','O','p','c','g','v','B','K','h','n','R','m',' ','C','k'};
     char alphabet[54] =  {'G','s','L','B','t','q','E','X','i','J','v','R','y','k','N','M','O','Z','c','a','.','h','w','f','T','j', 'z','S','n','Q','b','F','U','Y','e','p','x','I',' ','r','K','C','u','V','m','l','A','o','P','D','H','g','W','d'};
     string encrypt[54];
     char rotatechar[54];

     cout << "\n\n" << "--------------------------------------------------------------------------"<<"\n\n"<<"Decrypted Message:\n\n";


     // After finding the line from the file, the code performs the first part of the decryption process. 
     
     // It involves parsing the line into individual words, calculating a rotation value (r), 
     // and applying an anticlockwise rotation to an array (pp) based on this value.
     
     // A map (m) is created, associating characters from one array (charcater) with corresponding strings from another array (pp).
     // The file is closed after reading.
     string pp[54],word="";
     int nW=0;
     
     // parsing the line into individual words
     //'line' contains the encrpted message in word form
     for(auto x : line) ///This is a range-based for loop that iterates over each character (x) in the string line.
     {
      if(x == ' ') ///This checks if the current character x is a space. If it is, it means that a word has ended.
      {   
          pp[nW] = word; ///The word that has been built so far (stored in the word variable) is assigned to the nW-th element of the pp array.
          word = ""; ///word variable is reset to an empty string to start building the next word.
          nW++; ///counter nW is incremented to move to the next index in the pp array.
      }
      else ///If the current character is not a space, it means the character is part of a word.
      {
          word = word+x; ///The current character x is appended to the word variable, building the word character by character.
        ///   cout<<x;
          
      }
     }

     //Encryption me last ko rotate nhi kiya 
     string confuse=pp[53]; ///pointing last word  for rotation
    
     // calculating a rotation value
     int r = (int)confuse.at(0); /// initializes 'r' with ASCII value of 1st character of confuse string. This value is later used as a base for calculating the rotation.
     int sum_ = 0; ///used to accumulate the sum of ASCII values of characters in the confuse string.
     
     //  iterates through the characters of the confuse string
     for(int i=1;i<confuse.length();i++)
     {
        sum_ += (int)confuse.at(i);
     }
     r = r*(sum_); /// 'r' is multiplied by the calculated sum
     r = r%54; ///rotation value taken modulo 54, to ensure it remains within array indices.

     //  applying an anticlockwise rotation to an array (pp) based on value 'r'
     rotateAnticlockwise(pp,53,r);

     // A map (m) is created, associating characters from one array (charcater) with corresponding strings 
     //  from another array (pp).
     map<char,string> m; ///mapping line words to array of characters
     {
     for(int i=0;i<54;i++)
     {
       m.insert({charcater[i] , pp[i]});
     }
     }
     file.close(); // The file is closed after reading.


     // Another file is opened (filename_), and a line is read from it. 
     // The line is stored in the ep variable.
     // The code calculates shift values (shift and shiftm) based on characters found in the map (m). 
     // It then rotates two arrays (messagechar and charcater) based on these shift values.
     // Arrays of strings (encrypt, apl, and aplm) are created based on character arrays and mappings.
     // A random position (rp) is determined based on a character from the map (m).
     
     ifstream file_;
     string filename_ = "filename.txt";
     int line_number_ = 10; //To read the encrypted code of numbers
     if (line_number_ <= 0)
     {
       cout << "Line number must be >= 1" << endl;
       return 1;
     }
       file_.open(filename_); // Another file is opened (filename_), and a line is read from it.
       if (file_.fail())
     {
       cout << "File failed to open." << endl;
       return 1;
     }
       int currentline = 0;
       string line_;
     while (!file_.eof())
     {
       currentline++;
       getline(file_, line_);
       if (currentline == line_number_) break;
     }
       if (currentline < line_number_)
     {
       cout << "Line not found!" << endl;
       cout << "File contains " << currentline;
       cout << " lines total." << endl;
     }

       string ep=line_; // The line is stored in the ep variable.
  
       file_.close();


     // The code then enters a loop where it processes characters from the ep string.
     // It forms a string (check) by appending characters from ep until it reaches specific lengths (8, 10, 12, 14). 
     // For each such substring, it searches for a corresponding entry in the sorted keywords array and 
     //  outputs the associated character.
     string conf;
     auto pk=m.find('t'); //random
     conf = pk->second;

     int shift=(int)conf.at(0);
     int sum=0;
     for(int i=1;i<conf.length();i++)
     {
        sum+=(int)conf.at(i);
     }
     shift=shift*(sum);
     shift=shift%54;

      string confm;
     auto pkk=m.find('Y'); //random
     confm = pkk->second;

     int shiftm=(int)confm.at(0);
     int sum2=0;
     for(int i=1;i<confm.length();i++)
     {
        sum2+=(int)confm.at(i);
     }
     shiftm=shiftm*(sum2);
     shiftm=shiftm%54;

     rotateArray(messagechar,54,shiftm);

    rotateArray(charcater,54,shift);

    for(int i=0;i<54;i++)
    {
     string s;
     int asci=(int)charcater[i];
     if(asci>99)
      asci = asci %100;

     if(asci<10)
      s="0"+to_string(asci);
     else
      s=to_string(asci);

      encrypt[i]=s;
    }

    map<char,string> apl;
    {
    for(int i=0;i<54;i++)
    {
     apl.insert({alphabet[i] , encrypt[i]});
    }
    }

    map<char,string> aplm;
    {
    for(int i=0;i<54;i++)
    {
     aplm.insert({messagechar[i] , encrypt[i]});
    }
    }

    string sortedkeywords[54];

    string dp;
    auto kk=m.find('F');
    dp = kk->second;

    int rp=randomPosition(dp);

    for(int i=0;i<54;i++)
    {
    string st;
    auto it=m.find(alphabet[i]);
    st = it->second;

    string s;
    s=change(st,apl);

    string sub1,sub2;

    int pos=(int)alphabet[i] % rp;

    sub1 = s.substr(0,pos);
    sub2 = s.substr(pos,(st.length()*2)-pos);

    string p;
    auto tt=aplm.find(alphabet[i]);
    p=tt->second;

    st=sub1+p+sub2;

    sortedkeywords[i]=st;
  }
   string check;

   cout <<"\n";


   for(int i=0;i<ep.length();i++)
    {
      char ch=ep.at(i);

       check += ch;

        int vip=-1;

        if(check.length()==8 || check.length()==10 ||check.length()==12 ||check.length()==14) ///Encrypted 
        {

          for(int k=0;k<54;k++)
        {
           if(sortedkeywords[k] == check){
           vip=k;
           check="";
           break;
           }
        }
        }
        if(vip != -1)
        {
          cout <<alphabet[vip];
        }
     }

    // After the loop, a success message is printed to indicate that the message has been decrypted successfully.
    // The program ends with additional formatting.
cout<< "\n\n\n<<<<<<< The message Decrypted successfully >>>>>>>";
cout << "\n\n" << "--------------------------------------------------------------------------\n";
}
