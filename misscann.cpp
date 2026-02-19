/* CSCI1540
*
* Assignment  : 3
* Student ID  : 1155235807
* Name        : Kwok Ching Hin Alvin
* Email       : 1155235807@link.cuhk.edu.hk
*/

#include <iostream>
using namespace std;

void main() {
    int m,c,bs; /* m,c for ORIGINAL output of missonaries and cannibals */

    cout << "Enter #missionaries #cannibals: ";
    cin >> m >> c;
    cout << "Enter boat capacity: ";
    cin >> bs ;

    while ((((m<=0 || c<=0) || bs<2) || (c>m))) {
        cout << "Invalid input! Enter again." << endl;
        cout << "Enter #missionaries #cannibals: ";
        cin >> m >> c;
        cout << "Enter boat capacity: ";
        cin >> bs;
    }
    
    int rm, rc, lm, lc, bm, bc; /* r means right, l means left, b means boat */
    rm = m; /* original m,c value goes to right m,c */
    rc = c;
    lm = 0, lc = 0;
    cout << lm << "M " << lc << "C" << " ~~~~~\\_/ " << rm << "M " << rc << "C" << endl;

    int mark = 1; /* mark is the position of the boat, 1 means on the right, 0 means on the left, so original boat position should be on the right: 1 */
    while (rm>0 || !(rm == 0 && rc == 0) || !(rc > rm || lc > lm) && (rm != 0 && lm != 0)) {

        if (mark == 1) {
            cout << "Enter #m #c on board: ";
            cin >> bm >> bc;
            while ( (bm<0 || bc<0) || (bm==0 && bc==0) || ((bm+bc)>bs) || (bm>0 && bc>bm) || (bm>rm || bc>rc) ){
                cout << "Invalid input! Enter again." << endl;
                cout << "Enter #m #c on board: ";
                cin >> bm >> bc;
            }
            rm = rm - bm;
            rc = rc - bc;
            lm = lm + bm;
            lc = lc + bc;
            --mark; /* 1-1=0 so it goes to the left */
            cout << lm << "M " << lc << "C" << " \\_/~~~~~ " << rm << "M " << rc << "C" << endl;
        }
        if ((rc > rm || lc > lm) && (rm != 0 && lm != 0)) {
            cout << "Missionaries eaten! RIP.";
            break;
            mark += 2;
        }
        if (rm == 0 && rc == 0) {
            cout << "Well done!";
            break;
            mark += 2;
        }

        if (mark == 0) {
            cout << "Enter #m #c on board: ";
            cin >> bm >> bc;
            while ((bm < 0 || bc < 0) || (bm == 0 && bc == 0) || ((bm + bc) > bs) || (bm > 0 && bc > bm) || (bm > lm || bc > lc)) {
                cout << "Invalid input! Enter again." << endl;
                cout << "Enter #m #c on board: ";
                cin >> bm >> bc;
            }
            rm = rm + bm;
            rc = rc + bc;
            lm = lm - bm;
            lc = lc - bc;
            ++mark; /* 0+1=1 so it goes to the right */
            cout << lm << "M " << lc << "C" << " ~~~~~\\_/ " << rm << "M " << rc << "C" << endl;
        }
        if ((rc > rm || lc > lm) && (rm != 0 && lm != 0)) {
            cout << "Missionaries eaten! RIP.";
            break;
            mark += 2; /* There is no position marked as 2, so it must be out of the above if loops */
        }
        if (rm == 0 && rc == 0) {
            cout << "Well done!";
            break;
            mark += 2;
        }
    }
    
}
