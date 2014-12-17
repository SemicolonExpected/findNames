    ////// ////// ////// ////// ////// 
    //  // //     //       //     //
    ////// ////// //       //     //
    //  //     // //       //     //
    //  // ////// ////// ////// //////



g++ -std=c++0x sim300.cpp -o sim300
./sim300 i nSpartans nPersians > output.txt


If the program seems to have an infinite loop, it doesn't, it just takes a while
please be patient. Seriously if  you really want to simulate the Battle of
Thermopolis it will take at least 39000 however many uSeconds it takes to 
complete each run through. Seriously nothing crashed. I really don't suggest 
doing 100 iterations of 300 39000 because I started running the program at
exactly 12:08 and each iteration took: 15 minutes

Also 39000 doesnt seem to be enough to really overwhelm the Spartans, since
if all 300 spartans started with a low priority, it can worst case scenario
never hit a Persian as at a low value worst case to hit a priority of 50 it 
might take 300*49 iterations. If the first 300*49 persians were killed then it 
would take 2*300*49 iterations and so forth until there are no Persians left.
