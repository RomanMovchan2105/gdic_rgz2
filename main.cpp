//#include<iostream>
//#include<string>
//#include<fstream>

//using namespace std;

//int main(){
//   int width=6, height=5;
//   int **cell=new int*[width];
//for (int i=0; i<width;i++){
//    cell[i]=new int[height];
//}

//int **copy_cell=new int*[width];
//for (int i=0; i<width;i++){
// copy_cell[i]=new int[height];
//}

//ifstream ifs("bin.txt");
//   if (ifs.is_open()) {

//       for (int i=0; i<height; i++)
//            for (int j=0; j<width; j++){
//                 ifs >> cell[i][j];
//                 copy_cell[i][j]=0;
//                    }


//       cout << "Begin:\n";
//       for (int i=0; i<height; i++){
//            for (int j=0; j<width; j++){
//                 cout << cell[i][j]<< " ";
//            }     cout<<endl;}
//cout<<endl;

////cout << "\nSosedi:\n";
////
////for (int i=0; i<height; i++){
////     for (int j=0; j<width; j++){

////          cout << cell[i][j]<< ":";

//// if (i==0&&j==0){
////     cout << cell[height-1-i][width-1-j]<<" "<< cell[height-1][j]<<" "<< cell[height-1-i][1+j]<<" "
////          << cell[i][width-1]<<" "<< cell[i][j+1]<<" "
////          << cell[i+1][width-1-j]<<" "<< cell[i+1][j]<<" "<< cell[i+1][j+1]<<endl;
//// }

//// if (i==0&&j>0&&j<width-1){
////     cout << cell[height-1][j-1]<<" "<< cell[height-1][j]<<" "<< cell[height-1][1+j]<<" "
////          << cell[i][j-1]<<" "<< cell[i][j+1]<<" "
////          << cell[i+1][j-1]<<" "<< cell[i+1][j]<<" "<< cell[i+1][j+1]<<endl;
//// }

//// if (i==0&&j==width-1){
////     cout << cell[height-1][j-1]<<" "<< cell[height-1][j]<<" "<< cell[height-1][0]<<" "
////          << cell[i][j-1]<<" "<< cell[i][0]<<" "
////          << cell[i+1][j-1]<<" "<< cell[i+1][j]<<" "<< cell[i+1][0]<<endl;
//// }
//// if (i>0&&i<height-1&&j==0){
////     cout << cell[i-1][width-1]<<" "<< cell[i-1][j]<<" "<< cell[i-1][j+1]<<" "
////          << cell[i  ][width-1]<<" "<< cell[i][j+1]<<" "
////          << cell[i+1][width-1]<<" "<< cell[i+1][j]<<" "<< cell[i+1][j+1]<<endl;
//// }
//// if (i>0&&i<height-1&&j>0&&j<width-1){
////    cout  <<cell[i-1][j-1]<<" "<<cell[i-1][j  ]<<" "<<cell[i-1][j+1]
////          <<" "<<cell[i  ][j-1]<<" "<<cell[i][j+1]
////          <<" "<<cell[i+1][j-1]<<" "<<cell[i+1][j]<<" "<<cell[i+1][j+1]<<endl;
//// }

//// if (i>0&&i<height-1&&j==width-1){
////     cout << cell[i-1][j-1]<<" "<<cell[i-1][j  ]<<" "<< cell[i-1][0]<<" "
////          << cell[i][j-1]<<" "<< cell[i][0]<<" "
////          << cell[i+1][j-1]<<" "<< cell[i+1][j]<<" "<< cell[i+1][0]<<endl;
////}

//// if (i==height-1&&j==0){
////     cout << cell[i-1][width-1]<<" "<<cell[i-1][j  ]<<" "<< cell[i-1][j+1]<<" "
////          << cell[i][width-1]<<" "<< cell[i][j+1]<<" "
////          << cell[0][width-1]<<" "<< cell[0][j]<<" "<< cell[0][j+1]<<endl;
////}
//// if (i==height-1&&j>0&&j<width-1){
////     cout  <<cell[i-1][j-1]<<" "<<cell[i-1][j  ]<<" "<<cell[i-1][j+1]
////           <<" "<<cell[i  ][j-1]<<" "<<cell[i][j+1]<<" "
////          << cell[0][j-1]<<" "<< cell[0][j]<<" "<< cell[0][j+1]<<endl;
////}

//// if (i==height-1&&j==width-1){
////     cout  <<cell[i-1][j-1]<<" "<<cell[i-1][j  ]<<" "<<cell[i-1][0]
////           <<" "<<cell[i  ][j-1]<<" "<<cell[i][0]<<" "
////          << cell[0][j-1]<<" "<< cell[0][j]<<" "<< cell[0][0]<<endl;
////}
////     }
////     cout<<endl;
////}


//int sum=0, loop_count=0, step=1;
//bool game_over;

//do{
//    cout << "Step "<<step++<<"."<<endl;
//game_over=true;

//for (int i=0; i<height; i++){
//     for (int j=0; j<width; j++){
//        sum=0;


// if (i==0&&j==0){
//     sum=cell[height-1-i][width-1-j] + cell[height-1][j]+ cell[height-1-i][1+j]+
//         cell[i][width-1] + cell[i][j+1]+
//         cell[i+1][width-1-j] + cell[i+1][j] + cell[i+1][j+1];
// }
// if (i==0&&j>0&&j<width-1){
//      sum=cell[height-1][j-1] + cell[height-1][j]+ cell[height-1][1+j]+
//          cell[i][j-1] + cell[i][j+1]+
//          cell[i+1][j-1] + cell[i+1][j] + cell[i+1][j+1];
// }
// if (i==0&&j==width-1){
//     sum=cell[height-1][j-1] + cell[height-1][j] + cell[height-1][0] +
//         cell[i][j-1] + cell[i][0] +
//         cell[i+1][j-1] +  cell[i+1][j] +  cell[i+1][0];
// }
// if (i>0&&i<height-1&&j==0){
//     sum=cell[i-1][width-1] + cell[i-1][j] +  cell[i-1][j+1] +
//            cell[i  ][width-1] +  cell[i][j+1] +
//           cell[i+1][width-1] + cell[i+1][j] + cell[i+1][j+1];
// }
// if (i>0&&i<height-1&&j>0&&j<width-1){
//    sum=cell[i-1][j-1] + cell[i-1][j  ] + cell[i-1][j+1] +
//          cell[i  ][j-1] + cell[i][j+1] +
//         cell[i+1][j-1] + cell[i+1][j] + cell[i+1][j+1];
// }
// if (i>0&&i<height-1&&j==width-1){
//    sum= cell[i-1][j-1] + cell[i-1][j  ] + cell[i-1][0] +
//           cell[i][j-1] +  cell[i][0] +
//          cell[i+1][j-1] +  cell[i+1][j] +  cell[i+1][0];
//}
// if (i==height-1&&j==0){
//     sum=cell[i-1][width-1] + cell[i-1][j  ] + cell[i-1][j+1] +
//          cell[i][width-1] +  cell[i][j+1] +
//          cell[0][width-1] +  cell[0][j] +  cell[0][j+1];
//}
// if (i==height-1&&j>0&&j<width-1){
//     sum=cell[i-1][j-1] + cell[i-1][j  ] + cell[i-1][j+1] +
//          cell[i  ][j-1] + cell[i][j+1]  +
//          cell[0][j-1] + cell[0][j] +  cell[0][j+1];
//}
// if (i==height-1&&j==width-1){
//     sum=cell[i-1][j-1] + cell[i-1][j  ] + cell[i-1][0] +
//          cell[i  ][j-1] + cell[i][0] +
//        cell[0][j-1] + cell[0][j] + cell[0][0];
//}


//  if (cell[i][j]==1&& sum<2)          { cell[i][j]=0;/*break*/;}
//  if (cell[i][j]==1&& sum>3)          { cell[i][j]=0;/*break*/;}
//  if (cell[i][j]==1&& sum>=2&& sum<=3){ cell[i][j]=1;/*break*/;}
//  if (cell[i][j]==0&& sum==3)         { cell[i][j]=1;/*break*/;}
//     }
//}


////cout << "\nMain:\n";
//for (int i=0; i<height; i++){
//     for (int j=0; j<width; j++){
//          cout << cell[i][j]<< " ";
//     }     cout<<endl;}
//cout<<endl;

////cout << "\nCopy:\n";
////for (int i=0; i<height; i++){
////     for (int j=0; j<width; j++){
////          cout << cell[i][j]<< " ";
////     }     cout<<endl;}

//for (int i=0; i<height; i++){
//     for (int j=0; j<width; j++){
//        if(cell[i][j]==copy_cell[i][j]) {loop_count++;
//        }
//     }
//}

//for (int i=0; i<height; i++){
//     for (int j=0; j<width; j++){
//       copy_cell[i][j]=cell[i][j];
//     }
//  }




//for (int i=0; i<height; i++){
//     for (int j=0; j<width; j++){
//        if(cell[i][j]!=0) game_over=false;
//     }
//  }

//if(loop_count>=(width*height)) {game_over=true;  cout <<"It's endless loop\n";}


//}
//while (game_over==false);
//if (game_over) {cout <<"There are no more white cells. Thank you for playing!\n"; return 0;}









//   }
//   ifs.close();

//for (int i=0; i<width;i++)
//    delete[] cell[i];
//delete[] cell;

//for (int i=0; i<width;i++)
//    delete[] copy_cell[i];
//delete[] copy_cell;

//    return 0;
//}

