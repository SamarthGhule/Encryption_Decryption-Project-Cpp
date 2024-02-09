#include<bits/stdc++.h>
using namespace std;

static void rotateAnticlockwise(string arr[], int size, int rotations) {
    string temp[size];

    for (int i = 0; i < size; i++) {
        temp[i] = arr[i];
    }

    for (int i = 0; i < size; i++) {
        arr[(i - rotations + size) % size] = temp[i];
    }
}

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
   ifstream file;
  string filename="filename.txt";
  int line_number=4;
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
  int current_line = 0;
  string line;
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
     char messagechar[54] = {'a','f','g','F','H','p','C','r','T','h','w','S','x','z','K','l','Q','o','N','b','A','J','.','D','i','d','W','v','G','y','E','P','Y','O','M','L','U','Z','u','X','j','e','c','s','q','B','I','t','n','R','m',' ','V','k'};
     char charcater[54] = {'D','f','s','W','E','e','V','r','T','t','Y','.','U','z','I','l','i','o','P','b','A','J','S','a','Q','d','F','q','G','y','H','N','w','j','M','L','x','Z','u','X','O','p','c','g','v','B','K','h','n','R','m',' ','C','k'};
     char alphabet[54] =  {'G','s','L','B','t','q','E','X','i','J','v','R','y','k','N','M','O','Z','c','a','.','h','w','f','T','j', 'z','S','n','Q','b','F','U','Y','e','p','x','I',' ','r','K','C','u','V','m','l','A','o','P','D','H','g','W','d'};
     string encrypt[54];
     char rotatechar[54];

     cout << "\n\n" << "--------------------------------------------------------------------------"<<"\n\n"<<"Decrypted Message:\n\n";

     string pp[54],word="";
     int nW=0;
     for(auto x : line)
     {
      if(x==' ')
      {   pp[nW]=word;
          word="";
          nW++;
      }
      else
      {
          word=word+x;
      }
     }

     string confuse=pp[53];
    
     int r=(int)confuse.at(0);
     int sum_=0;
     for(int i=1;i<confuse.length();i++)
     {
        sum_+=(int)confuse.at(i);
     }
     r=r*(sum_);
     r=r%54;

     rotateAnticlockwise(pp,53,r);

     map<char,string> m;
     {
     for(int i=0;i<54;i++)
     {
       m.insert({charcater[i] , pp[i]});
     }
     }
     file.close();

     ifstream file_;
     string filename_="filename.txt";
     int line_number_=10;
     if (line_number_ <= 0)
     {
       cout << "Line number must be >= 1" << endl;
       return 1;
     }
       file_.open(filename_);
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

       string ep=line_;
  
       file_.close();

     string conf;
     auto pk=m.find('t');
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
     auto pkk=m.find('Y');
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

        if(check.length()==8 || check.length()==10 ||check.length()==12 ||check.length()==14)
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

cout<< "\n\n\n<<<<<<< The message Decrypted successfully >>>>>>>";
cout << "\n\n" << "--------------------------------------------------------------------------\n";
}