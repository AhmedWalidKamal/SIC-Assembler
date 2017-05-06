////
//// Created by Walid on 5/3/2017.
////
//
//#include <iostream>
//#include "../file/read/FileReader.h"
//#include "../pass2/PassTwoController.h"
//#include "../statement/Statement.h"
//#include <vector>
//int main() {
//    // File name should be with a relative path.
////    std::string fileName = "sicEx.asm";
////    FileReader *fileReader = new FileReader(fileName);
//    std::unordered_map<std::string, int> instructionTable;
//   instructionTable.insert({{"ADD",24},{"AND",64},{"COMP",40},{"DIV",36},{"J",60},{"JEQ",48},{"JGT",52},{"JLT",56}
//                                   ,{"JSUB",72},{"LDA",0},{"LDCH",80},{"LDL",8},{"LDX",4},{"MUL",32},{"OR",68},{"RD",216},{"RSUB",76},
//                                   {"STA",12},{"STCH",84},{"STL",20},{"STX",16},{"SUB",28},{"TD",224},{"TIX",44},{"WD",220}});
//    std::unordered_map<std::string, int> symbolTable;
//    symbolTable.insert({{"FIVE",4108},{"ALPHA",4114},{"CHRZ",4111},{"C1",4117},{"FIRST",4096}});
//    std::vector<Statement>statements;
//    std::vector<bool>hasLabel(10);
//    std::vector<int>operandsValue(10);
//    for(int i=0;i<10;i++){
//        hasLabel[i]=false;
//        operandsValue[i]=0;
//    }
//    /*statement 1*/
//    Statement s;
//    //s=new Statement();
//    int locationCounter=4096;
//    s.setStatementLocationPointer(locationCounter);
//    Label *l;
//    l=new Label("COPY");
//    l->setLabelField("COPY");
//    s.setLabel(l);
//    Mnemonic *m;
//    m=new Mnemonic("START");
//    s.setMnemonic(m);
//    Operand *p;
//    p=new Operand();
//   //p->setIntValue(4096);
//    operandsValue[0]=4096;
//    s.setOperand(p);
//    statements.push_back(s);
//
//    /*statement 2*/
//    Statement s2;
//    s2.setStatementLocationPointer(locationCounter);
//    Label *l2;
//    l2=new Label("FIRST");
//    l2->setLabelField("FIRST");
//    s2.setLabel(l2);
//    hasLabel[1]=true;
//    Mnemonic *m2;
//    m2=new Mnemonic("LDA");
//    s2.setMnemonic(m2);
//    Operand *p2;
//    p2=new Operand("FIVE");
//    s2.setOperand(p2);
//    statements.push_back(s2);
//
//    /*statement 3*/
//    Statement s3;
//    locationCounter+=3;
//    s3.setStatementLocationPointer(locationCounter);
//    Mnemonic *m3;
//     m3=new Mnemonic("STA");
//    s3.setMnemonic(m3);
//    Operand *p3;
//    p3=new Operand("ALPHA");
//    s3.setOperand(p3);
//    hasLabel[2]=true;
//    statements.push_back(s3);
//
//    /*statement 4*/
//    Statement s4;
//    locationCounter+=3;
//    s4.setStatementLocationPointer(locationCounter);
//    Mnemonic *m4;
//     m4=new Mnemonic("LDCH");
//    s4.setMnemonic(m4);
//    Operand *p4;
//    p4=new Operand("CHRZ");
//    s4.setOperand(p4);
//    hasLabel[3]=true;
//    statements.push_back(s4);
//
//    /*statement 5*/
//    Statement s5;
//    locationCounter+=3;
//    s5.setStatementLocationPointer(locationCounter);
//    Mnemonic *m5;
//    m5=new Mnemonic("STCH");
//    s5.setMnemonic(m5);
//    Operand *p5;
//    p5=new Operand("C1");
//    s5.setOperand(p5);
//    hasLabel[4]=true;
//    statements.push_back(s5);
//
//    /*statement 6*/
//    Statement s6;
//    locationCounter+=3;
//    s6.setStatementLocationPointer(locationCounter);
//    Label *l6;
//    l6=new Label("FIVE");
//    l6->setLabelField("FIVE");
//    s6.setLabel(l6);
//    Mnemonic *m6;
//    m6=new Mnemonic("WORD");
//    s6.setMnemonic(m6);
//    Operand *p6;
//    p6=new Operand();
////    p6->setIntValue(5);
//    operandsValue[5]=5;
//    s6.setOperand(p6);
//    statements.push_back(s6);
//
//    /*statement 7*/
//    Statement s7;
//    locationCounter+=3;
//    s7.setStatementLocationPointer(locationCounter);
//    Label *l7;
//    l7=new Label("CHRZ");
//    l7->setLabelField("CHRZ");
//    s7.setLabel(l7);
//    Mnemonic *m7;
//    m7=new Mnemonic("BYTE");
//    s7.setMnemonic(m7);
//    Operand *p7;
//    p7=new Operand("Z");
//    s7.setOperand(p7);
//    statements.push_back(s7);
//
//    /*statement 8*/
//    Statement s8;
//    locationCounter+=3;
//    s8.setStatementLocationPointer(locationCounter);
//    Label *l8;
//    l8=new Label("ALPHA");
//    l8->setLabelField("ALPHA");
//    s8.setLabel(l8);
//    Mnemonic *m8;
//     m8=new Mnemonic("RESW");
//    s8.setMnemonic(m8);
//    Operand *p8;
//    p8=new Operand();
////    p8->setIntValue(1);
//    operandsValue[7]=1;
//    s8.setOperand(p8);
//    statements.push_back(s8);
//
//    /*statement 9*/
//    Statement s9;
//    locationCounter+=3;
//    s9.setStatementLocationPointer(locationCounter);
//    Label *l9=new Label("C1");
//    l9->setLabelField("C1");
//    s9.setLabel(l9);
//    Mnemonic *m9;
//    m9=new Mnemonic("RESB");
//    s9.setMnemonic(m9);
//    Operand *p9;
//    p9=new Operand();
////    p9->setIntValue(1);
//    operandsValue[8]=1;
//    s9.setOperand(p9);
//    statements.push_back(s9);
//
//    /*statement 10*/
//    Statement s10;
//    Mnemonic *m10;
//     m10=new Mnemonic("END");
//    s10.setMnemonic(m10);
//    Operand *p10;
//    p10=new Operand("FIRST");
//    s10.setOperand(p10);
//    hasLabel[9]=true;
//    statements.push_back(s10);
//
//    PassTwoController *pass2 = new PassTwoController(hasLabel,operandsValue,statements,30,"outFile.txt","listingFile.txt",instructionTable,symbolTable);
//    pass2->executePass2();
//    return 0;
//}
//

