/* UVa 10033 The Interpreter: http://isaac.lsu.edu/uva/100//10033.html */
#include <cstdio>
#include <string.h>
using namespace std;

static const int HALT = 1000;

static int count = 0;
static short reg[10] = {};
static short ram[1000] = {};
static bool halt = false;

inline short execute(short inst) {
    short i, o1, o2;
    short jump = -1;

    o2 = inst%10;
    inst /= 10;
    o1 = inst%10;
    inst /= 10;
    i = inst%10;

        switch(i) {
        case 1:
            //100 means halt
            halt = true;
            break;
        case 2:
            //2dn means set register d to n (between 0 and 9)
            reg[o1] = o2;
            break;
        case 3:
            //3dn means add n to register d
            reg[o1] = (reg[o1] + o2) % 1000;
            break;
        case 4:
            //4dn means multiply register d by n
            reg[o1] = (reg[o1] * o2) % 1000;
            break;
        case 5:
            //5ds means set register d to the value of register s
            reg[o1] = reg[o2];
            break;
        case 6:
            //6ds means add the value of register s to register d
            reg[o1] = (reg[o1] + reg[o2]) % 1000;
            break;
        case 7:
            //7ds means multiply register d by the value of register s
            reg[o1] = (reg[o1] * reg[o2]) % 1000;
            break;
        case 8:
            //8da means set register d to the value in RAM whose address is in register a
            reg[o1] = ram[reg[o2]];
            break;
        case 9:
            //9sa means set the value in RAM whose address is in register a to the value of register s
            ram[reg[o2]] = reg[o1];
            break;
        case 0:
            //0ds means goto the location in register d unless register s contains 0
            if (reg[o2] != 0) jump = reg[o1];
            break;
        default:
            break;
    } //switch

    count++;
    if(halt) return HALT;
    else return jump;
}

int main() {
    short n, nextinst;
    //string inst;
    char inst[10];
    char peek;
    int addr = 0;

    scanf("%d", &n);

    getchar();
    getchar();

    while(n--) {
        halt = false;

        while((peek = getchar()) != EOF && peek != '\n') {
            scanf("%s", inst);
            getchar();
            ram[addr++] = (peek - '0')*100 + (inst[0] - '0')*10 + inst[1] - '0';
        }

        //start executing instructions from RAM address 000
        addr = 0;
        while(addr < 1000) {
            nextinst = execute(ram[addr]);
            if(nextinst < 0) addr++;
            else if(nextinst >= HALT) break; //HALT
            else addr = nextinst;
        }
        printf("%d\n", count);
        if (n > 0) printf("\n");

        memset(ram, 0, 1000 * sizeof(short));
        memset(reg, 0, 10 * sizeof(short));

        count = addr = 0;
    }

    return 0;
}
