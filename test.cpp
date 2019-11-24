#include "hungarian.hpp"

int main(){
  int h=1;
  Hungarian test;
  ifstream testfile("largesttest.txt");
  test.Load_and_build(testfile);
  test.Solve(h);

  // Hungarian test2;
  // int i,j;
  // vector<double> helper;
  // test2.Mymatrix.clear();
  // helper.clear();
  // helper.push_back(10);
  // helper.push_back(10);
  // helper.push_back(0);
  // helper.push_back(10);
  // helper.push_back(10);
  // helper.push_back(0);
  // test2.Mymatrix.push_back(helper);
  // test2.Mymatrix.push_back(helper);
  // helper.clear();
  // helper.push_back(0);
  // helper.push_back(10);
  // helper.push_back(10);
  // helper.push_back(0);
  // helper.push_back(10);
  // helper.push_back(10);
  // test2.Mymatrix.push_back(helper);
  // helper.clear();
  // helper.push_back(10);
  // helper.push_back(10);
  // helper.push_back(0);
  // helper.push_back(10);
  // helper.push_back(10);
  // helper.push_back(0);
  // test2.Mymatrix.push_back(helper);
  // helper.clear();
  // helper.resize(6,0);
  // test2.Mymatrix.push_back(helper);
  // test2.Mymatrix.push_back(helper);
  //
  // test2.Mymatrix_height=6;
  // test2.Mymatrix_width=6;
  // test2.Mymatrix_paper_no=4;
  // cout << "Mymatrix is " << '\n';
  // for(i=0;i<6;i++){
  //   for(j=0;j<6;j++){
  //     cout <<test2.Mymatrix[i][j] <<" ";
  //   }
  //   cout << '\n';
  // }
  //
  //
  // test2.Coverzeros();
  // std::cout << "final_row_assignments is " << '\n';
  // for(i=0;i<6;i++){
  //   std::cout << test2.final_row_assignment[i] << " ";
  // }
  // std::cout << '\n';
  // std::cout << "final_col_assignments is " << '\n';
  // for(i=0;i<6;i++){
  //   std::cout << test2.final_col_assignment[i] << " ";
  // }
  // std::cout << '\n';
  // std::cout << "row_mark is " << '\n';
  // for(i=0;i<6;i++){
  //   std::cout << test2.row_mark[i] << " ";
  // }
  // std::cout << '\n';
  // std::cout << "col_mark is " << '\n';
  // for(i=0;i<6;i++){
  //   std::cout << test2.col_mark[i] << " ";
  // }
  // std::cout << '\n';
  // cout << "Matrix_lines is " << '\n';
  // for(i=0;i<test2.Mymatrix_height;i++){
  //   for(j=0;j<test2.Mymatrix_width;j++){
  //     cout <<test2.Matrix_lines[i][j] <<" ";
  //   }
  //   cout << '\n';
  // }
  // std::cout << "number of lines is " <<test2.Number_of_lines<< '\n';

  // Hungarian test3;
  // int i,j;
  // vector<double> helper;
  // test3.Mymatrix.clear();
  // helper.clear();
  // helper.push_back(0);
  // helper.push_back(10);
  // helper.push_back(10);
  // test3.Mymatrix.push_back(helper);
  // helper.clear();
  // helper.push_back(10);
  // helper.push_back(0);
  // helper.push_back(10);
  // test3.Mymatrix.push_back(helper);
  // helper.clear();
  // helper.push_back(10);
  // helper.push_back(10);
  // helper.push_back(0);
  // test3.Mymatrix.push_back(helper);
  //
  // test3.Mymatrix_height=3;
  // test3.Mymatrix_width=3;
  // test3.Mymatrix_paper_no = 3;
  // cout << "Mymatrix is " << '\n';
  // for(i=0;i<3;i++){
  //   for(j=0;j<3;j++){
  //     cout <<test3.Mymatrix[i][j] <<" ";
  //   }
  //   cout << '\n';
  // }
  //
  // test3.Coverzeros();
  // std::cout << "final_row_assignments is " << '\n';
  // for(i=0;i<3;i++){
  //   std::cout << test3.final_row_assignment[i] << " ";
  // }
  // std::cout << '\n';
  // std::cout << "final_col_assignments is " << '\n';
  // for(i=0;i<3;i++){
  //   std::cout << test3.final_col_assignment[i] << " ";
  // }
  // std::cout << '\n';
  // std::cout << "row_mark is " << '\n';
  // for(i=0;i<3;i++){
  //   std::cout << test3.row_mark[i] << " ";
  // }
  // std::cout << '\n';
  // std::cout << "col_mark is " << '\n';
  // for(i=0;i<3;i++){
  //   std::cout << test3.col_mark[i] << " ";
  // }
  // std::cout << '\n';
  // cout << "Matrix_lines is " << '\n';
  // for(i=0;i<test3.Mymatrix_height;i++){
  //   for(j=0;j<test3.Mymatrix_width;j++){
  //     cout <<test3.Matrix_lines[i][j] <<" ";
  //   }
  //   cout << '\n';
  // }
  // std::cout << "number of lines is " <<test3.Number_of_lines<< '\n';

  // Hungarian test4;
  // int i,j;
  // vector<double> helper;
  // test4.Mymatrix.clear();
  // helper.clear();
  // helper.push_back(0);
  // helper.push_back(10);
  // helper.push_back(10);
  // helper.push_back(10);
  // test4.Mymatrix.push_back(helper);
  // helper.clear();
  // helper.push_back(10);
  // helper.push_back(10);
  // helper.push_back(10);
  // helper.push_back(0);
  // test4.Mymatrix.push_back(helper);
  // helper.clear();
  // helper.push_back(0);
  // helper.push_back(10);
  // helper.push_back(10);
  // helper.push_back(10);
  // test4.Mymatrix.push_back(helper);
  // helper.clear();
  // helper.push_back(10);
  // helper.push_back(0);
  // helper.push_back(0);
  // helper.push_back(10);
  // test4.Mymatrix.push_back(helper);
  //
  // test4.Mymatrix_paper_no=4;
  // test4.Mymatrix_height=4;
  // test4.Mymatrix_width=4;
  // cout << "Mymatrix is " << '\n';
  // for(i=0;i<4;i++){
  //   for(j=0;j<4;j++){
  //     cout <<test4.Mymatrix[i][j] <<" ";
  //   }
  //   cout << '\n';
  // }
  //
  //
  // test4.Coverzeros();
  // std::cout << "final_row_assignments is " << '\n';
  // for(i=0;i<4;i++){
  //   std::cout << test4.final_row_assignment[i] << " ";
  // }
  // std::cout << '\n';
  // std::cout << "final_col_assignments is " << '\n';
  // for(i=0;i<4;i++){
  //   std::cout << test4.final_col_assignment[i] << " ";
  // }
  // std::cout << '\n';
  // std::cout << "row_mark is " << '\n';
  // for(i=0;i<4;i++){
  //   std::cout << test4.row_mark[i] << " ";
  // }
  // std::cout << '\n';
  // std::cout << "col_mark is " << '\n';
  // for(i=0;i<4;i++){
  //   std::cout << test4.col_mark[i] << " ";
  // }
  // std::cout << '\n';
  // cout << "Matrix_lines is " << '\n';
  // for(i=0;i<test4.Mymatrix_height;i++){
  //   for(j=0;j<test4.Mymatrix_width;j++){
  //     cout <<test4.Matrix_lines[i][j] <<" ";
  //   }
  //   cout << '\n';
  // }
  // std::cout << "number of lines is " <<test4.Number_of_lines<< '\n';
  return 0;
}
