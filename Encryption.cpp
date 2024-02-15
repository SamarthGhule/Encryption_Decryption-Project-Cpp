#include<bits/stdc++.h>
using namespace std;

//This function takes an array of strings (arr), its size (size), and the number of rotations (rotations). 
// It rotates the elements in the array clockwise by the specified number of rotations.
static void rotateClockwise(string arr[], int size, int rotations) {
    string temp[size];

    for (int i = 0; i < size; i++) {
        temp[i] = arr[i];
    }

    for (int i = 0; i < size; i++) {
        arr[(i + rotations) % size] = temp[i];
    }
}

//This function takes an array of characters (arr), its size (n), and the number of rotations (k). 
// It rotates the elements in the array to the right by the specified number of rotations.
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

// This function takes a string (dp) and calculates a random position based on the ASCII values of its characters.
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

// This function generates an array of 54 random numbers between 0 and n.
static int* randomNumber(int n)
{
    int* arr = new int[54];

    srand(time(0));
    for(int i=0;i<54;i++){
    arr[i] = rand() % n;
    }
    return arr;
}

// This function takes a string (st) and a map (apl) containing character mappings. 
// It encrypts the input string based on the mappings in the map.
static string encryptSt(string st,map<char ,string>& apl)
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

int main()
{

     // Opens an output file named "filename.txt" using ofstream MyFile("filename.txt");. 
     // ofstream is a stream class to write data to files.
     ofstream MyFile("filename.txt");
    
     // An array of characters representing a message
     char messagechar[54] = {'a','f','g','F','H','p','C','r','T','h','w','S','x','z','K','l','Q','o','N','b','A','J','.','D',
     'i','d','W','v','G','y','E','P','Y','O','M','L','U','Z','u','X','j','e','c','s','q','B','I','t','n','R','m',' ','V','k'};
     

     // Initializing three arrays messagechar, charcater, and alphabet. 
     // messagechar represents the original message, charcater and alphabet represent different rotations of characters.
     // Arrays representing different rotations of the characters
     char charcater[54] = {'D','f','s','W','E','e','V','r','T','t','Y','.','U','z','I','l','i','o','P','b','A','J','S','a','Q',
     'd','F','q','G','y','H','N','w','j','M','L','x','Z','u','X','O','p','c','g','v','B','K','h','n','R','m',' ','C','k'};
     char alphabet[54] =  {'G','s','L','B','t','q','E','X','i','J','v','R','y','k','N','M','O','Z','c','a','.','h','w','f','T',
     'j','z','S','n','Q','b','F','U','Y','e','p','x','I',' ','r','K','C','u','V','m','l','A','o','P','D','H','g','W','d'};
     string encrypt[54]; //'encrypt' array points Code for message/normal characters
     char rotatechar[54];
     string keyWords[54]; //'keywords' array points Code for normal characters
     
     // 2660 words----- taken 2660 different English words of four different sizes(3,4,5,6)
     string Words[]={
"aal","aam","aba","abb","abo","abs","aby","ace","ach","ack","act","add","ado","ads","adz","aft","age","ago","aha","aid","aim","air","ale",
"all","ant","any","ape","app","apt","arc","are","arf","ark","arm","aro","ars","art","ash","ask","ass","ate","awe","awk","aww","axe","aye",
"ayu","baa","bac","bad","bae","bag","bah","bam","ban","bar","bat","bay","baz","bed","bee","beg","ben","bet","bib","bid","big","bin","bit",
"bix","boa","bog","boi","boo","bop","bot","bow","box","boy","bra","bro","brr","bud","bug","bum","bun","bus","but","buy","bye","bzz","cab",
"cam","can","cap","car","cat","caw","cel","chi","cob","cod","cog","com","con","coo","cop","cot","cum","cwm","dam","der","die","dig","dim",
"din","dog","dry","ego","emo","erg","ess","exe","exy","fab","fad","fag","fam","fan","far","fat","few","fin","fit","gal","gap","gas","gel",
"get","ghi","gin","goy","gum","gun","gut","guy","ham","hat","her","hit","hod","hog","hot","how","hut","ich","ick","imu","ire","ivy","jam",
"kar","key","kin","las","Law","lay","lie","lin","lol","low","lox","mad","mag","map","mas","max","mid","mix","mun","nef","nil","nim","nop",
"now","nun","oak","odd","off","oho","pad","pan","pay","peg","pel","pen","pet","pin","pix","pox","pub","pyx","qin","ram","red","Red","rim",
"rod","rye","sac","sad","sen","sig","sin","sit","sly","sny","son","sub","sun","ted","tee","tel","the","tho","til","tin","uck","vac","vai",
"van","var","vas","vat","vau","vav","vaw","vee","veg","vet","vex","via","vie","vig","vim","vis","voe","vow","vox","vug","wad","wae","wag",
"wan","wap","war","was","wat","waw","wax","way","web","wed","wee","wen","wet","wha","who","why","wig","win","wis","wit","wiz","woe","wog",
"wok","won","woo","wop","wos","wot","wow","wry","wud","wye","wyn","xat","xis","yah","yak","yam","yap","yar","yaw","yay","yea","yee","yeh",
"yen","yep","yes","yet","yew","yex","yid","yin","yip","yob","yod","yok","yon","you","yow","yuk","yum","yup","zag","zap","zax","zed","zee",
"zek","zen","zho","zig","zin","zip","zit","zoa","zoo","arch","area","army","atom","atop","aunt","aura","avid","away","axis","baby","bach",
"back","bail","bait","bake","bald","ball","band","bang","bank","bare","bark","barn","base","bass","bath","bats","beam","bean","bear","beat",
"beck","beef","been","beer","bell","belt","bend","bent","best","beta","beth","bias","bike","bill","bind","bird","bite","blew","bloc","blog",
"blow","blue","blur","boat","body","boil","bold","bolt","bomb","bond","bone","book","boom","boon","boot","bore","born","boss","both","bout",
"bowl","brad","bred","brew","brow","buck","bulb","bulk","bull","bump","burn","bury","bush","bust","busy","butt","buzz","cafe","cage","cake",
"calf","call","calm","came","camp","cane","cape","card","care","carl","carr","cart","cash","cast","cave","cell","cent","chad","chap","chat",
"chef","chic","chin","chip","chop","cite","city","clad","clan","clay","clip","club","clue","coal","coat","coca","code","coil","coin","coke",
"cola","cold","cole","come","cone","conn","cook","cool","cope","copy","cord","core","cork","corn","cost","coup","cove","crap","crew","crop",
"crow","cube","cult","curb","cure","cute","dale","dame","damn","damp","dare","dark","dash","data","date","dawn","days","dead","deaf","deal",
"dean","dear","debt","deck","deed","deep","deer","dell","demo","dent","deny","desk","dial","dice","dick","diet","dire","dirt","disc","dish",
"disk","dive","dock","does","dole","doll","dome","done","doom","door","dose","dove","down","drag","draw","drew","drop","drug","drum","dual",
"duck","duff","duke","dull","duly","dumb","dump","dusk","dust","duty","each","earl","earn","ease","east","easy","eats","echo","edge","edit",
"envy","epic","euro","even","ever","evil","exam","exit","expo","eyed","face","fact","fade","fail","fair","fake","fall","fame","fare","farm",
"fast","fate","fear","feat","feed","feel","feet","fell","felt","file","fill","film","find","fine","fire","firm","fish","fist","five","flag",
"flat","fled","flee","flew","flex","flip","flow","flux","foam","foil","fold","folk","fond","font","food","fool","foot","ford","fore","fork",
"form","fort","foul","four","free","frog","from","fuck","fuel","full","fund","fury","fuse","fuss","gain","gala","gale","gall","game","gang",
"gate","gave","gaze","gear","gene","gift","gill","girl","give","glad","glen","glow","glue","goal","goat","goes","gold","golf","gone","good",
"gore","gown","grab","gram","gray","grew","grey","grid","grim","grin","grip","grow","gulf","guru","hail","hair","hale","half","hall","halt",
"hand","hang","hank","hard","harm","hart","hate","haul","have","hawk","head","heal","heap","hear","heat","heel","heir","held","hell","helm",
"help","herb","herd","here","hero","hers","hide","high","hike","hill","hint","hire","hold","hole","holt","holy","home","hood","hook","hope",
"horn","hose","host","hour","huge","hull","hung","hunt","hurt","hype","icon","idea","idle","idol","inch","info","into","iris","iron","isle",
"item","jack","jail","jake","jane","java","jazz","jean","jeep","jill","joey","john","join","joke","josh","jump","junk","jury","just","keen",
"keep","kemp","kent","kept","khan","kick","kill","kind","king","kirk","kiss","kite","knee","knew","knit","knot","know","kohl","Kyle","lace",
"lack","lady","laid","lake","lamb","lamp","land","lane","lang","last","late","lava","lawn","lazy","lead","leaf","leak","lean","leap","left",
"lend","lens","lent","less","lest","levy","lied","lien","life","lift","lone","look","loop","lord","lose","loss","lost","loud","love","luck",
"lump","lung","lure","lush","lust","made","maid","mail","main","make","male","mall","mama","many","marc","mark","mart","mask","mass","mate",
"matt","mayo","maze","mead","meal","mean","meat","meet","Mega","melt","memo","menu","mere","mesa","mesh","mess","mice","mick","mike","mild",
"mile","milk","mill","mind","mine","mini","mint","miss","mist","mock","mode","mold","monk","mood","moon","more","moss","most","move","much",
"must","myth","nail","name","navy","near","neat","neck","need","nest","news","next","nice","nick","nine","node","none","noon","norm","nose",
"note","nova","nude","nuts","oath","obey","odds","odor","okay","once","only","onto","open","oral","otto","ours","oval","oven","over","pace",
"pack","pact","page","paid","pain","pair","pale","palm","papa","para","park","part","pass","past","path","peak","peat","peck","peel","peer",
"pest","pick","pier","pike","pile","pill","pine","pink","pint","pipe","pity","plan","play","plea","plot","plug","plus","poem","poet","pole",
"poll","polo","poly","pond","pony","pool","poor","pope","pork","port","pose","post","pour","pray","prep","prey","prof","prop","pull","pulp",
"pump","punk","pure","push","quid","quit","quiz","race","rack","rage","raid","rail","rain","ramp","rang","rank","rape","rare","rash","rate",
"rave","read","real","reap","rear","reed","reef","reel","rely","rent","rest","rice","rich","rick","ride","ring","riot","ripe","rise","risk",
"rite","ritz","road","roar","rock","rode","role","roll","roof","room","root","rope","rose","ruby","rude","ruin","rule","rush","rust","ruth",
"sack","safe","saga","sage","said","sail","sake","sale","salt","same","sand","sang","sank","save","scan","scar","scot","seal","seat","seed",
"seek","seem","seen","self","sell","semi","send","sent","sept","sexy","shah","shed","ship","shit","shoe","shop","shot","show","shut","sick",
"side","sigh","sign","silk","sing","sink","site","size","skin","skip","slab","slam","slap","slid","slim","slip","slot","slow","snap","snow",
"soap","soar","soda","sofa","soft","soil","sold","sole","solo","some","song","soon","sore","sort","soul","soup","sour","span","spin","spit",
"spot","spun","spur","star","stay","stem","step","stir","stop","such","suck","suit","sung","sunk","sure","surf","swan","swap","sway","swim",
"tack","tail","take","tale","talk","tall","tank","tape","taps","task","taxi","team","tear","tech","teen","tell","tend","tent","term","test",
"text","than","that","them","then","they","thin","thou","thus","tick","tide","tidy","tier","tile","till","tilt","time","tiny","tire","toby",
"told","toll","tomb","tone","tony","took","tool","tops","tore","torn","tort","toss","tour","town","trap","tray","tree","trek","trim","trio",
"trip","troy","tube","tuck","tuna","tune","turf","turn","twin","type","ugly","unit","upon","urge","used","user","vain","vary","vast","veil",
"vein","verb","very","vest","veto","vice","view","vine","visa","vote","wade","wage","wait","wake","walk","wall","want","ward","ware","warm",
"warn","wary","wash","watt","wave","ways","weak","wear","weed","week","well","went","were","west","what","when","whip","whom","wide","wife",
"wild","will","wind","wine","wing","wipe","wire","wise","wish","with","woke","wolf","wood","wool","word","wore","work","worm","worn","wrap",
"yang","yard","yarn","yeah","year","your","yuan","zero","zinc","zone","zoom","Acute","Alive","Alone","Angry","Aware","Awful","Basic","Black",
"Blind","Brave","Brief","Broad","Brown","Cheap","Chief","Civil","Clean","Clear","Close","Crazy","Daily","Dirty","Early","Empty","Equal","Exact",
"Extra","Faint","False","Fifth","Final","First","Fresh","Front","Funny","Giant","Grand","Great","Green","Gross","Happy","Harsh","Heavy","Human",
"Ideal","Inner","Joint","Large","Legal","Level","Light","Local","Loose","Lucky","Magic","Major","Minor","Moral","Naked","Nasty","Naval","Other",
"Outer","Plain","Prime","Prior","Proud","Quick","Quiet","Rapid","Ready","Right","Roman","Rough","Round","Royal","Rural","Sharp","Sheer","Short",
"Silly","Sixth","Small","Smart","Solid","Sorry","Spare","Steep","Still","Super","Sweet","Thick","Third","Tight","Total","Tough","Upper","Upset",
"Urban","Usual","Vague","Valid","Vital","White","Whole","Wrong","Young","Agent","Anger","Apple","Award","Basis","Beach","Birth","Block","Blood",
"Board","Brain","Bread","Break","Brown","Buyer","Cause","Chain","Chair","Chest","Chief","Child","China","Claim","Class","Clock","Coach","Coast",
"Court","Cover","Cream","Crime","Cross","Crowd","Crown","Cycle","Dance","Death","Depth","Doubt","Draft","Drama","Dream","Dress","Drink","Drive",
"Earth","Enemy","Entry","Error","Event","Faith","Fault","Field","Fight","Final","Floor","Focus","Force","Frame","Frank","Front","Fruit","Glass",
"Grant","Grass","Green","Group","Guide","Heart","Henry","Horse","Hotel","House","Image","Index","Input","Issue","Japan","Jones","Judge","Knife",
"Laura","Layer","Level","Lewis","Light","Limit","Lunch","Major","March","Match","Metal","Model","Money","Month","Motor","Mouth","Music","Night",
"Noise","North","Novel","Nurse","Offer","Order","Other","Owner","Panel","Paper","Party","Peace","Peter","Phase","Phone","Piece","Pilot","Pitch",
"Place","Plane","Plant","Plate","Point","Pound","Power","Press","Price","Pride","Prize","Proof","Queen","Radio","Range","Ratio","Reply","Right",
"River","Round","Route","Rugby","Scale","Scene","Scope","Score","Sense","Shape","Share","Sheep","Sheet","Shift","Shirt","Shock","Sight","Simon",
"Skill","Sleep","Smile","Smith","Smoke","Sound","South","Space","Speed","Spite","Sport","Squad","Staff","Stage","Start","State","Steam","Steel",
"Stock","Stone","Store","Study","Stuff","Style","Sugar","Table","Taste","Terry","Theme","Thing","Title","Total","Touch","Tower","Track","Trade",
"Train","Trend","Trial","Trust","Truth","Uncle","Union","Unity","Value","Video","Visit","Voice","Waste","Watch","Water","While","White","Whole",
"Woman","World","Youth","Agree","Allow","Alter","Apply","Argue","Arise","Avoid","Begin","Blame","Break","Bring","Build","Burst","Carry","Catch",
"Cause","Check","Claim","Clean","Clear","Climb","Close","Count","Cover","Cross","Dance","Doubt","Drink","Drive","Enjoy","Enter","Exist","Fight",
"Focus","Force","Guess","Imply","Issue","Judge","Laugh","Learn","Leave","Limit","Marry","Match","Occur","Offer","Order","Phone","Place","Point",
"Press","Prove","Raise","Reach","Refer","Relax","Serve","Shall","Share","Shift","Shoot","Sleep","Solve","Sound","Speak","Spend","Split","Stand",
"Start","State","Stick","Study","Teach","Thank","Think","Throw","Touch","Train","Treat","Trust","Visit","Voice","Waste","Watch","Worry","Would",
"Write","Every","Abacus","Abject","Ablaze","Abroad","Abrupt","Absorb","Abused","Accept","Access","Accuse","Admire","Adored","Advant","Advise","Affect",
"Afford","Afraid","Agreed","Alarms","Albeit","Alerts","Aligns","Allege","Alleys","Allots","Almond","Almost","Alpaca","Alumna","Ambush","Amount","Amused",
"Anally","Anchor","Angers","Angled","Angles","Animes","Anodes","Anyone","Apache","Appeal","Appear","Appeal","Arched","Arches","Ardeny","Argued","Arisen",
"Armada","Arrays","Arrive","Artful","Artist","Ascent","Assign","Assure","Asthma","Athena","Attack","Attain","Attire","August","Aurora","Awaken","Awaken",
"Abates","Aborts","Abused","Accent","Accuse","Adored","Adores","Aeries","Affair","Affect","Better","Beyond","Bishop","Border","Bottle","Bottom","Bought",
"Branch","Breath","Bridge","Bright","Broken","Budget","Burden","Bureau","Button","Baffle","Balcon","Baldly","Ballot","Ballet","Bamboo","Banter","Barbed",
"Barren","Basalt","Basket","Battle","Beachy","Beacon","Beaker","Beamed","Beaten","Beauty","Bedlam","Before","Behind","Belfry","Bended","Berate","Beside",
"Bestir","Betide","Bigger","Billow","Bindle","Binged","Binned","Bisect","Bitten","Bladed","Blamed","Blazed","Blonde","Blotch","Blowup","Boated","Bodily",
"Boiled","Bolted","Borrow","Bouncy","Bovine","Boxers","Brewer","Broker","Bruise","Brutal","Bucket","Camera","Cancer","Cannot","Carbon","Career","Castle",
"Casual","Caught","Center","Centre","Chance","Change","Charge","Choice","Choose","Chosen","Church","Circle","Client","Closed","Closer","Coffee","Column",
"Combat","Coming","Common","Comply","Copper","Corner","Costly","County","Couple","Course","Covers","Create","Credit","Crisis","Custom","Damage","Danger",
"Dealer","Debate","Decade","Decide","Defeat","Defend","Define","Degree","Demand","Depend","Deputy","Desert","Design","Desire","Detail","Detect","Device",
"Differ","Dinner","Direct","Doctor","Dollar","Domain","Double","Driven","Driver","During","Easily","Eating","Editor","Effect","Effort","Eighth","Either",
"Eleven","Emerge","Empire","Employ","Enable","Ending","Energy","Engage","Engine","Enough","Ensure","Entire","Entity","Equity","Escape","Estate","Ethnic",
"Exceed","Except","Excess","Expand","Expect","Expert","Export","Extend","Extent","Fabric","Facing","Factor","Failed","Fairly","Fallen","Family","Famous",
"Father","Fellow","Female","Figure","Filing","Finger","Finish","Fiscal","Flight","Flying","Follow","Forced","Forest","Forget","Formal","Format","Former",
"Foster","Fought","Fourth","French","Friend","Future","Garden","Gather","Gender","German","Global","Golden","Ground","Growth","Guilty","Gabble","Gadget",
"Gainly","Gallop","Gamble","Gamely","Gazing","Geneva","Gently","Giggle","Ginger","Girdle","Gladly","Glazed","Glitch","Gloomy","Glowed","Gluten","Goggle",
"Gossip","Graded","Grains","Grassy","Grater","Gravel","Grease","Greedy","Groove","Grudge","Guided","Guitar","Gunner","Gurgle","Gabber","Gables","Gaffes",
"Gaiety","Gainer","Gander","Gangly","Gawked","Gelled","Ghetto","Hacker","Haggle","Halter","Hamlet","Handle","Hangar","Hanger","Happen","Harass","Harbor",
"Hardly","Harmed","Hazard","Heated","Heaven","Herbal","Hereby","Heroes","Herpes","Hinder","Hinged","Hissed","Hoarse","Homily","Hooded","Hoofed","Hookah",
"Hornet","Horrid","Horsed","Hosted","Howard","Humble","Hunter","Hurled","Hurray","Hurted","Hutter","Hybrid","Hyster","Hacked","Hagged","Hailed","Hailer",
"Halers","Haling","Handed","Headed","Health","Height","Hidden","Holder","Honest","Impact","Import","Income","Indeed","Injury","Inside","Intend","Intent",
"Invest","Island","Itself","Igloos","Impala","Inning","Island","Impose","Innate","Instep","Irides","Inward","Istles","Indent","Indium","Iodize","Infant",
"Influx","Infamy","Insult","Injure","Invest","Invite","Indict","Inland","Insane","Ironic","Iodine","Irises","Ironed","Irides","Issued","Innate","Jersey",
"Joseph","Junior","Jagged","Jamaat","Jamjar","Jangle","Jargon","Jarvis","Jellys","Jersey","Jetsam","Jigsaw","Jingle","Jobbed","Jogged","Johnie","Joiner",
"Joking","Jumble","Jumble","Jumped","Junker","Jungle","Junior","Junket","Jurors","Juries","Jutted","Killed","Kabbal","Kaleid","Kanish","Kapoor","Karnak",
"Kateri","Kettle","Keypad","Khanum","Kielce","Kilter","Kimchi","Kinder","Kingly","Kipper","Kismet","Kitbag","Kitten","Kittle","Klaive","Knight","Knives",
"Knocks","Knolly","Knotty","Knower","Kokomo","Komodo","Koodoo","Labour","Latest","Latter","Launch","Lawyer","Leader","League","Leaves","Legacy","Length",
"Lesson","Letter","Lights","Likely","Linked","Liquid","Listen","Little","Living","Losing","Lucent","Luxury","Mainly","Making","Manage","Manner","Manual",
"Margin","Marine","Marked","Market","Martin","Master","Matter","Mature","Medium","Member","Memory","Mental","Merely","Merger","Method","Middle","Miller",
"Mining","Minute","Mirror","Mobile","Modern","Modest","Module","Moment","Morris","Mostly","Mother","Motion","Moving","Murder","Museum","Mutual","Myself",
"Narrow","Nation","Native","Nature","Nearby","Nearly","Nights","Nobody","Normal","Notice","Notion","Number","Nacred","Nagano","Nagged","Nagger","Nailed",
"Namers","Naming","Napead","Napkin","Narked","Nassau","Natter","Navies","Nawabs","Nectar","Needed","Object","Obtain","Office","Offset","Online","Option",
"Orange","Origin","Output","Oxford","Oafish","Obeyed","Oblast","Oblong","Oboist","Obsess","Obtuse","Obvert","Occult","Ocelli","Ochery","Octane","Octant",
"Octave","Octavo","Ocular","Oddest","Oddity","Oedema","Offend","Ogling","Ogives","Ogress","Ohmage","Oiling","Oilman","Oilmen","Okapis","Okayed","Oldest",
"Oldies","Olives","Omegas","Omelet","Omenti","Omened","Onager","Onions","Onside","Onward","Oology","Opaque","Openly","Operas","Opiate","Opined","Oppose",
"Optics","Optima","Optime","Oracle","Orchid","Oregan","Orgeat","Orient","Ormolu","Ornate","Orogen","Oroide","Orphan","Orrice","Osmose","Otitis","Ounces",
"Outfit","Outing","Outlaw","Outran","Outdid","Packed","Palace","Parent","Partly","Patent","People","Period","Permit","Person","Phrase","Picked","Planet",
"Player","Please","Plenty","Pocket","Police","Policy","Prefer","Pretty","Prince","Prison","Profit","Proper","Proven","Public","Pursue","Raised","Random",
"Rarely","Rather","Rating","Reader","Really","Reason","Recall","Recent","Record","Reduce","Reform","Regard","Regime","Region","Relate","Relief","Remain",
"Remote","Remove","Repair","Repeat","Replay","Report","Rescue","Resort","Result","Retail","Retain","Return","Reveal","Review","Reward","Riding","Rising",
"Robust","Ruling","Safety","Salary","Sample","Saving","Saying","Scheme","School","Screen","Search","Season","Second","Secret","Sector","Secure","Seeing",
"Select","Seller","Senior","Series","Server","Settle","Severe","Sexual","Should","Signal","Signed","Silent","Silver","Simple","Simply","Single","Sister",
"Slight","Smooth","Social","Solely","Sought","Source","Soviet","Speech","Spirit","Spoken","Spread","Spring","Square","Stable","Status","Steady","Stolen",
"Strain","Stream","Street","Stress","Strict","Strike","String","Strong","Struck","Studio","Submit","Sudden","Suffer","Summer","Summit","Supply","Surely",
"Survey","Switch","Symbol","System","Taking","Talent","Target","Taught","Tenant","Tender","Tennis","Thanks","Theory","Thirty","Though","Threat","Thrown",
"Ticket","Timely","Timing","Tissue","Toward","Travel","Treaty","Trying","Twelve","Twenty","Uberty","Udding","Uglify","Uglier","Uglies","Uglily","Upping",
"Upbore","Upcast","Upcome","Update","Updive","Updove","Upheap","Upheld","Uphill","Uphold","Uphove","Uplift","Uplink","Upload","Upmost","Uprise","Uproar",
"Uproot","Upsend","Upshot","Upsoar","Upstay","Upstir","Upwell","Upwind","Urbane","Urchin","Urgent","Urinal","Usance","Ushaka","Usurer","Utmost","Unable",
"Unique","United","Unless","Unlike","Useful","Vacant","Vacate","Vacuum","Vagary","Vagile","Vagina","Vaguer","Vainly","Valise","Valley","Valors","Valour",
"Valued","Valuer","Values","Vamped","Vandal","Vapors","Vapory","Varias","Varies","Varied","Varlet","Varnas","Vasare","Vassal","Vatted","Vealer","Veered",
"Veggie","Veiled","Velars","Velets","Vellum","Velour","Velure","Venial","Venice","Venous","Vented","Venues","Verbal","Verify","Verily","Verism","Verity",
"Vermes","Vermil","Vernal","Versal","Vertex","Vesper","Vessel","Vested","Vetted","Vexers","Vexils","Vexing","Vialed","Viands","Vibist","Vicars","Viewer",
"Vigors","Vigour","Villed","Villus","Vinery","Vineal","Vinous","Violas","Vipers","Virago","Vendor","Versus","Victim","Vision","Visual","Volume","Walker",
"Wealth","Weekly","Weight","Wholly","Window","Winner","Winter","Within","Wonder","Worker","Wright","Writer","Yellow","Yachts","Yacker","Yammer","Yanked",
"Yapper","Yclept","Yearly","Yeasts","Yecchs","Yelled","Yodled","Yogurt","Yonder","Yttria","Yuppie"
 };

cout << "\n\n" << "--------------------------------------------------------------------------";
// cout<< "\n\n";

// Using array of integers p[54] as an index to extract words from the string array 'Words' to create private phrase.
MyFile <<  " The Private phrase is :" << "\n \n\n";
int * p = randomNumber(2660);

//cout<< "Random positions\n";
// for(int i=0;i<54;i++)
// {
//     cout<< p[i]<<" , ";
// }

cout<<"\n";

//Arranging random strings from array of string 'Words' taking random numbers from random numbers array 'p' 
for(int i=0;i<54;i++)
{
    keyWords[i]=Words[p[i]]; //'keywords' array points Code for normal characters
   // cout<<keyWords[i] <<" ";
}
cout<<"\n\n";

     string confuse=keyWords[53];
    
     int r=(int)confuse.at(0);
     int sum_=0;
     for(int i=1;i<confuse.length();i++)
     {
        sum_+=(int)confuse.at(i);
     }
     r=r*(sum_);
     r=r%54;

// rotates the elements in array clockwise by the specified number of rotations.
rotateClockwise(keyWords,53,r);

// writing the content of keyWords array to the file associated with MyFile
for(int i=0;i<54;i++)
{
 MyFile << keyWords[i] <<" ";
}

MyFile << "\n\n\n";

// Mapping each charater of 'charcater' array to a specific string from a random sequence of strings
map<char,string> m;
{
for(int i=0;i<54;i++)
{
 m.insert({charcater[i] , Words[p[i]]}); 
}
cout<<"\n";
}

     // generating unique two-digit random codes form "normal characters" and "message characters"
     string conf;
     auto pk=m.find('t');
     conf = pk->second;

    //  Creating a shift value which will going to be random and by that shift value we will rotate the above 
    //  array and use the last two digits ASCII value of these characters to create our two-digit code for each 
    //  character of our assigned word

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

// rotated the character array with our generated shift value
     rotateArray(messagechar,54,shiftm);

     rotateArray(charcater,54,shift);


// created 2–digit code by the last 2 digits of ASCII of these characters and saved it in encrypt[] array of string type.
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

// created a map named 'apl' where we are mapping characters of the alphabet[] to our randomly generated code
map<char,string> apl; //Mapping to generate code for normal characters
{
for(int i=0;i<54;i++)
{
 apl.insert({alphabet[i] , encrypt[i]}); //'encrypt' array points Code for normal characters
}
}


// Similarly, generating another set of codes for encrypting the characters of the user input message
map<char,string> aplm; //Mapping to generate code for message characters
{
for(int i=0;i<54;i++)
{
 aplm.insert({messagechar[i] , encrypt[i]}); //'encrypt' array points Code for message characters
}
}

// cout<< "Code for normal characters"<<"\n";
// for(auto pr:apl)
// {
//     cout<< pr.first<<" : "<< pr.second<<"\n";
// }
// cout<<"\n\n";
// cout << "Code for message characters"<<"\n";
// for(auto p:aplm)
// {
//     cout<< p.first<<" : "<< p.second<<"\n";
// }


    string dp;
    auto kk=m.find('F');
    dp = kk->second;

    int rp=randomPosition(dp);

string message;

cout << "Enter the message below :" << " \n\n\n";
getline(cin , message);
cout <<"\n\n";

             MyFile << "Encrypted message : \n\n\n";


// Encryption of every character of message
for(int i=0;i<message.length();i++)
{
    //Encryption of single message character in one go
    char ch=message.at(i);

    string st;
    auto it=m.find(ch);
    st = it->second;

    string s;

    s=encryptSt(st,apl);

    string sub1,sub2;

    int pos=(int)ch % rp;

    sub1 = s.substr(0,pos);
    sub2 = s.substr(pos,(st.length()*2)-pos);

    string op;
    auto tt=aplm.find(ch);
    op=tt->second;

    s=sub1+op+sub2;

     MyFile<<s;
}
     // After all rotations, the file is closed.
     MyFile.close();

cout <<"<<<<<<< Message Encryped Successfuly And Saved In Message File >>>>>>>";

cout << "\n\n"<<"--------------------------------------------------------------------------"<<"\n\n";


}
