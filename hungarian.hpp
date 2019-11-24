#ifndef Hungarian_H
#define Hungarian_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;
class Hungarian{
public:
Hungarian();
~Hungarian();
void Load_and_build(ifstream& assigment);               // load the data and build matrix
void Solve(int h);                                      // solve the matrix, each paper is assigned to h reviewer
void Reset();                                          // Reset

// private:
vector<vector<double>> Original_matrix;
vector<vector<double>> Transformed_matrix;
vector<vector<int> > Matrix_lines;
vector<vector<double>> Mymatrix;
int Mymatrix_reviewer_no;
int Mymatrix_paper_no;
int Mymatrix_width;
int Mymatrix_height;
vector<int> Solution_row_paper;
vector<int> Solution_col_reviewer;
int smallest_reviewer_no;
int smallest_paper_no;
double score_largest;
int lack_of_reviewer;

void Print_matrix();
void Coverzeros();
int Number_of_lines;
void Addzeros();
int Record(int col_num);
vector<int> final_rows;  // containing rows value
vector<int> final_cols; // containing col values
void Recordsol();
void Modify();
// void DrawLines(int i, int j, int result);
// int Judge(int i, int j);
int Safetopush(int i);
vector<int> assignment_for_covering_zeros; // helper for assignment vector
vector<int> assignment;   // element recording cols number
vector<int> final_row_assignment; // used for covering zeros
vector<int> final_col_assignment;
int Assign_paper_to_most_reviewer(int row_number, vector<int>* parent);
int Unassigned(int col_number);
void Mark_rows_cols();
vector<int> row_mark;
vector<int> col_mark;
void DrawLines();
};
#endif
