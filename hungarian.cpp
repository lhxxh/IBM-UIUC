#include "hungarian.hpp"
#include <algorithm>
#include <cmath>
#include <iostream>

Hungarian::Hungarian(){}

Hungarian::~Hungarian(){}

void Hungarian::Print_matrix(){
  int i;
  // int j;

  cout << "Mymatrix_reviewer_no is " <<Mymatrix_reviewer_no<< '\n';
  cout << "Mymatrix_paper_no is " <<Mymatrix_paper_no<< '\n';
  cout << "Mymatrix_width is " <<Mymatrix_width<< '\n';
  cout << "Mymatrix_height is " <<Mymatrix_height<< '\n';
  // cout << "Original_matrix is " << '\n';
  // for(i=0;i<Mymatrix_paper_no;i++){
  //   for(j=0;j<Mymatrix_reviewer_no;j++){
  //     cout <<Original_matrix[i][j] <<" ";
  //   }
  //   cout << '\n';
  // }
  // cout << "Transformed_matrix is " << '\n';
  // for(i=0;i<Mymatrix_height;i++){
  //   for(j=0;j<Mymatrix_width;j++){
  //     cout <<Transformed_matrix[i][j] <<" ";
  //   }
  //   cout << '\n';
  // }
  // cout << "Mymatrix is " << '\n';
  // for(i=0;i<Mymatrix_height;i++){
  //   for(j=0;j<Mymatrix_width;j++){
  //     cout <<Mymatrix[i][j] <<" ";
  //   }
  //   cout << '\n';
  // }
// for debug purpose
  // cout << "Matrix_lines is " << '\n';
  // for(i=0;i<Mymatrix_height;i++){
  //   for(j=0;j<Mymatrix_width;j++){
  //     cout <<Matrix_lines[i][j] <<" ";
  //   }
  //   cout << '\n';
  // }

  std::cout << "the result is shown below" << '\n';
  std::cout << "Solution_row_paper is " << '\n';
  for(i=0;i<(int)Solution_row_paper.size();i++){
    std::cout <<Solution_row_paper[i] <<" ";
  }
  std::cout << '\n';
  std::cout << "Solution_col_reviewer is " << '\n';
  for(i=0;i<(int)Solution_col_reviewer.size();i++){
    std::cout << Solution_col_reviewer[i] << " ";
  }
  std::cout << '\n';
  return;
}

void Hungarian::Load_and_build(ifstream& assignment){

vector <int> reviewer_no, paper_no;
vector <double> score;
vector <double> score_helper;
vector<int>::iterator result;
vector<double>::iterator score_it;

int i,j,k;
int reviewer_largest, reviewer_smallest, paper_largest, paper_smallest;
string reviewer_str,paper_str,score_str;

int helper_counter=0;

while(assignment>>paper_str>>reviewer_str>>score_str){  // score_largest only serve as temp store
  reviewer_no.push_back(stoi(reviewer_str));
  paper_no.push_back(stoi(paper_str));
  score.push_back(stod(score_str));
  helper_counter+=1;
}

// cout << "paper_no is " << "\n";
// for ( i = 0; i < helper_counter; i++) {
// std::cout <<paper_no[i]<<" " ;
// }
// std::cout << '\n';
// cout<<"reviewer_no is "<<"\n";
// for ( i = 0; i < helper_counter; i++) {
// std::cout <<reviewer_no[i]<<" " ;
// }
// std::cout << '\n';
// cout << "score is " <<"\n";
// for ( i = 0; i < helper_counter; i++) {
// std::cout <<score[i]<<" " ;
// }
// std::cout << '\n';

for(i=0;i<(int)reviewer_no.size();i++){
    result=max_element(reviewer_no.begin(),reviewer_no.end());
    reviewer_largest=*result;
    result=min_element(reviewer_no.begin(),reviewer_no.end());
    reviewer_smallest=*result;
    Mymatrix_reviewer_no=reviewer_largest-reviewer_smallest+1;

    result=max_element(paper_no.begin(),paper_no.end());
    paper_largest=*result;
    result=min_element(paper_no.begin(),paper_no.end());
    paper_smallest=*result;
    Mymatrix_paper_no=paper_largest-paper_smallest+1;
}

smallest_paper_no=paper_smallest;
smallest_reviewer_no=reviewer_smallest;

Mymatrix.resize(Mymatrix_paper_no);
Original_matrix.resize(Mymatrix_paper_no);
for(i=0;i<Mymatrix_paper_no;i++){
  Mymatrix[i].resize(Mymatrix_reviewer_no,0.0);
  Original_matrix[i].resize(Mymatrix_reviewer_no,0.0);
}


score_it=max_element(score.begin(),score.end());
score_largest=*score_it;                            // largest score
// step 1 maximaize the score matrix
// for(i=0;i<Mymatrix_paper_no;i++){
//   for (j=0;j<Mymatrix_reviewer_no;j++) {
//    Original_matrix[i][j]=score[j+i*Mymatrix_reviewer_no];
// std::cout << "i is "<<i<< " with j is "<<j<<" score is "<< score[Mymatrix_paper_no*j+i] << '\n';
//    Mymatrix[i][j]=score[Mymatrix_paper_no*j+i]*(-1)+score_largest;
//   }
// }

for(i=0;i<helper_counter;i++){
  Original_matrix[paper_no[i]-paper_smallest][reviewer_no[i]-reviewer_smallest]=score[i];
  // std::cout << "paper_no is " <<paper_no[i]-paper_smallest<< " reviewer_no is "<<reviewer_no[i]-reviewer_smallest<< " score is "<< score[i]<<'\n';
  Mymatrix[paper_no[i]-paper_smallest][reviewer_no[i]-reviewer_smallest]=score[i]*(-1)+score_largest;
}


//step 2 make number of row and col the same
j=1+((Mymatrix_paper_no-1)/Mymatrix_reviewer_no);     //determine the copy needed
if(j>1){
  Mymatrix_width=Mymatrix_reviewer_no*j;
  for(i=0;i<Mymatrix_paper_no;i++){
    score_helper=Mymatrix[i];
      for(k=1;k<j;k++)
        Mymatrix[i].insert(Mymatrix[i].end(),score_helper.begin(),score_helper.end());
      }
}
else
  Mymatrix_width=Mymatrix_reviewer_no;

if(Mymatrix_paper_no==Mymatrix_width)
  Mymatrix_height=Mymatrix_paper_no;

else {
  k=Mymatrix_width-Mymatrix_paper_no;
  score_helper.clear();                               // clear contents before reuse
  score_helper.resize(Mymatrix_width,score_largest);
  for(i=0;i<k;i++)
    Mymatrix.push_back(score_helper);
  Mymatrix_height=Mymatrix.size();
}

Transformed_matrix=Mymatrix;

return;
}

void Hungarian::Reset(){
  // Solution_row_paper.clear();
  // Solution_col_reviewer.clear();
  // Mymatrix=Transformed_matrix;
}

void Hungarian::Solve(int h){
  int i,j,k;
  double smallest_number;
  vector<double>::iterator it;
  vector<double> helper;
  int show_iteration=0;

if(h==0){
  std::cout << "It does not make sense to assign the paper 0 times" << '\n';;
  return;
}
else if(h>Mymatrix_reviewer_no){
  std::cout << "One paper cannot be assigned to the same reviewer twice or more" << '\n';
  return;
}

Solution_col_reviewer.clear();
Solution_row_paper.clear();
lack_of_reviewer=Mymatrix_paper_no*h;
for(k=0;k<h || lack_of_reviewer>0;k++){
//subtraction in row                   step 1
for(i=0;i<Mymatrix_height;i++){
  it=min_element(Mymatrix[i].begin(),Mymatrix[i].end());
  smallest_number= 0 > *it ? 0 : *it;
  if (smallest_number > 0){
    for(j=0;j<Mymatrix_width;j++)
      Mymatrix[i][j]-=smallest_number;
    }
  }
// subtraction in column               step 2
for(j=0;j<Mymatrix_width;j++){
  helper.clear();
  for(i=0;i<Mymatrix_height;i++)
    helper.push_back(Mymatrix[i][j]);

    it=min_element(helper.begin(),helper.end());
    smallest_number= 0 > *it ? 0 : *it;
    if(smallest_number > 0){
      for(i=0;i<Mymatrix_height;i++)
        Mymatrix[i][j]-=smallest_number;
    }
  }
// cover and add zeros                 step 3
// std::cout << "look here!!!!!!!!" << '\n';
Coverzeros();

// cout << "fist after cover zero " << '\n';
// for(i=0;i<Mymatrix_height;i++){
//   for(j=0;j<Mymatrix_width;j++){
//     cout <<Matrix_lines[i][j] <<" ";
//   }
//   cout << '\n';
// }

while( Number_of_lines < Mymatrix_width ){
Addzeros();

// cout << "after add zeros at iteration " <<show_iteration<< '\n';
// for(i=0;i<Mymatrix_height;i++){
//   for(j=0;j<Mymatrix_width;j++){
//     cout <<Mymatrix[i][j] <<" ";
//   }
//   cout << '\n';
// }

Coverzeros();

// cout << "after cover zeros at it " <<show_iteration<< '\n';
// for(i=0;i<Mymatrix_height;i++){
//   for(j=0;j<Mymatrix_width;j++){
//     cout <<Matrix_lines[i][j] <<" ";
//   }
//   cout << '\n';
// }

show_iteration+=1;
}
// record and modify each iteration result  step 4
final_rows.clear();
Record(0);
Recordsol();
Modify();
}

Print_matrix();
return;
}

void Hungarian::Addzeros(){
  int i,j;
  double min_score=2;

  for(i=0;i<Mymatrix_height;i++)
    for(j=0;j<Mymatrix_width;j++)
    if(Matrix_lines[i][j]==0 && Mymatrix[i][j]<min_score)
      min_score= Mymatrix[i][j];

  for(i=0;i<Mymatrix_height;i++){
    for(j=0;j<Mymatrix_width;j++){
      if(Matrix_lines[i][j]==2){
        Mymatrix[i][j]+=min_score;
      }
      else if(Matrix_lines[i][j]==0){
        Mymatrix[i][j]-=min_score;
      }
    }
  }
  return;
}

int Hungarian::Record(int col_num){
  if (col_num == Mymatrix_width)
    return 1;
  else{
    int i;
    for(i=0;i<Mymatrix_height;i++){
      if(Mymatrix[i][col_num]==0 && Safetopush(i)==1){
        final_rows.push_back(i);
        if(Record(col_num+1))
          return 1;
        else
          final_rows.pop_back();
      }
    }
    return 0;
  }
}

int Hungarian::Safetopush(int i){
  int m;

  for(m=0;m<(int)final_rows.size();m++)
    if(final_rows[m]==i)
      return 0;

  return 1;
}

void Hungarian::Recordsol(){
  int i;
  // first we have to check whether there is any repeat in final rows
  for(i=0;i<Mymatrix_width;i++){
    if(Transformed_matrix[final_rows[final_rows.size()-1-i]][final_rows.size()-1-i]==2)
      final_rows[final_rows.size()-1-i]=-1;
  }
  // then we load the value to human readable row-col pairs
  for(i=0;i<Mymatrix_width;i++){
    if(final_rows[i]<Mymatrix_paper_no && final_rows[i] != -1){
    Solution_col_reviewer.push_back((i%Mymatrix_reviewer_no)+smallest_reviewer_no);
    Solution_row_paper.push_back(final_rows[i]+smallest_paper_no);
    lack_of_reviewer-=1;
      }
    }

return;
}

void Hungarian::Modify(){
int i,k;
int first_repeat_position;

Mymatrix=Transformed_matrix;
for(k=0;k<(int)final_rows.size();k++){
  if(final_rows[k]<Mymatrix_paper_no && final_rows[k] != -1){
  Mymatrix[final_rows[k]][k]=2;                            // 2 means it has been selected before
  first_repeat_position=k%Mymatrix_reviewer_no;
  for(i=first_repeat_position;i<Mymatrix_width;i+=Mymatrix_reviewer_no){
    Mymatrix[final_rows[k]][i]=2;
  }
 }
}
Transformed_matrix=Mymatrix;
return;
}

// void Hungarian::Coverzeros(){
//   int i,j,result;
//
//   Number_of_lines=0;
//   Matrix_lines.clear();
//   Matrix_lines.resize(Mymatrix_height);
//   for(i=0;i<Mymatrix_height;i++)
//     Matrix_lines[i].resize(Mymatrix_width,0);
//   for(i=0;i<Mymatrix_height;i++)
//     for(j=0;j<Mymatrix_width;j++){
//       if(Mymatrix[i][j]==0){
//       result=Judge(i,j);
//       DrawLines(i,j,result);
//      }
//     }
// }

// int Hungarian::Judge(int i, int j){
//   int k,m;
//   int row_zero_number=0,col_zero_number=0;
//   int result;
//
//   for(k=0;k<Mymatrix_width;k++)
//     if(Mymatrix[i][k]==0)
//       row_zero_number+=1;
//
//   for(m=0;m<Mymatrix_height;m++)
//     if(Mymatrix[m][j]==0)
//       col_zero_number+=1;
//
//   result = col_zero_number>row_zero_number ? -1 : 1;
//   return result;
// }

// void Hungarian::DrawLines(int i, int j, int result){
//   int m;
//   if(Matrix_lines[i][j]==2)   // colored twice
//     return;
//   else if (Matrix_lines[i][j]==1 && result==1)  // colored row again
//     return;
//   else if (Matrix_lines[i][j]==-1 && result==-1)  // colored col again
//     return;
//
//   else{
//     if(result == 1){                   // color row
//       for(m=0;m<Mymatrix_width;m++)
//         Matrix_lines[i][m]= Matrix_lines[i][m]==2 || Matrix_lines[i][m]==-1 ? 2:1 ;
//     }
//     else                             // color col
//       for(m=0;m<Mymatrix_height;m++)
//         Matrix_lines[m][j]= Matrix_lines[m][j]==2 || Matrix_lines[m][j]==1 ? 2:-1;
//
//   }
// Number_of_lines+=1;
// return;
// }
void Hungarian::Coverzeros(){
  int i;
  vector<int> temp;

  Number_of_lines=0;
  temp.clear();
  final_row_assignment.clear();
  final_col_assignment.clear();
  assignment_for_covering_zeros.clear();
  assignment.clear();
  assignment.resize(Mymatrix_height,-1);
  Assign_paper_to_most_reviewer(0,&temp);
  for(i=(int)temp.size()-1; i>-1 ;i--){
    final_row_assignment.push_back(temp[i]);
  }
  final_col_assignment.resize(Mymatrix_width,-1);
  for(i=0; i<(int)final_row_assignment.size(); i++){
    if(final_row_assignment[i] != -1){
    final_col_assignment[final_row_assignment[i]]=i;
    }
  }
  row_mark.clear();
  row_mark.resize(Mymatrix_height,0);
  col_mark.clear();
  col_mark.resize(Mymatrix_width,0);
  Mark_rows_cols();
  DrawLines();
  return;
}

int Hungarian::Assign_paper_to_most_reviewer(int row_number, vector<int>* parent){
  int i,j;
  int ret=-1;
  vector<int> ret_values;
  vector<int>::iterator it;
  // int flag_for_none_assignment;
  vector<int> child;
  vector<vector<int>> possible_path;
  int alert=0;

  if(row_number == Mymatrix_height || row_number > Mymatrix_height)
    return 0;

  possible_path.clear();
  ret_values.clear();
  ret_values.resize(Mymatrix_width,-1);
  for(i=0;i<Mymatrix_width;i++){
    if((Mymatrix[row_number][i] == 0) && (Unassigned(i) == 1)){
      assignment_for_covering_zeros.push_back(i);
      child.clear();
      j=Assign_paper_to_most_reviewer(row_number+1,&child);
      child.push_back(i);
      possible_path.push_back(child);
      ret_values[i]=j;
      assignment_for_covering_zeros.pop_back();
      alert = 1;
      if (row_number == Mymatrix_paper_no || row_number > Mymatrix_paper_no){break;} // newly added
      if (j == (Mymatrix_height-(row_number+1))){break;}  // newly added
    }
  }

  if(row_number < Mymatrix_paper_no && alert == 0){                 // newly added
  // flag_for_none_assignment=1;
  // for(it= ret_values.begin(); it != ret_values.end(); it++){
  //   if(*it != -1){
  //     flag_for_none_assignment=0;
  //     break;
  //   }
  // }

  // if(flag_for_none_assignment == 1){
      assignment_for_covering_zeros.push_back(-1);
      child.clear();
      ret=Assign_paper_to_most_reviewer(row_number+1,&child);
      child.push_back(-1);
      possible_path.push_back(child);
      assignment_for_covering_zeros.pop_back();
  // }
}

  assignment[row_number]=-1;
   for(i=0; i<(int)ret_values.size(); i++){
    if(ret_values[i] > ret){
      ret=ret_values[i];
      assignment[row_number]=i;
      if (row_number == Mymatrix_paper_no || row_number > Mymatrix_paper_no){break;} // newly added
      if ( ret == (Mymatrix_height-(row_number+1))){break;} // newly added
    }
   }

  if(assignment[row_number]== -1){
    // the last line case
    if(row_number == Mymatrix_height-1){
      parent->push_back(-1);
    }
    else{
      for(i=0; i<(int)possible_path.size(); i++){
        if(possible_path[i].back() == assignment[row_number]){
          *parent= possible_path[i];
          break;
        }
      }
    }
    return ret;
  }
  else{
    // the last line case
    if(row_number == Mymatrix_height-1){
      parent->push_back(assignment[row_number]);
    }
    else{
      for(i=0; i<(int)possible_path.size(); i++){
        if(possible_path[i].back() == assignment[row_number]){
          *parent= possible_path[i];
          break;
        }
      }
    }
    return (ret+1);
  }
}

int Hungarian::Unassigned(int col_num){
  vector<int>::iterator it;
  for(it=assignment_for_covering_zeros.begin(); it != assignment_for_covering_zeros.end();it++){
    if(*it == col_num)
      return 0;
  }
  return 1;
}

void Hungarian::Mark_rows_cols(){
  int i,j;
  int mode;
  vector<int> last_row_mark;
  vector<int> last_col_mark;

  for(i=0 ;i<(int)final_row_assignment.size(); i++){
    if(final_row_assignment[i] == -1){
      row_mark[i]= 1;
    }
  }

  last_col_mark.clear();
  last_col_mark.resize(Mymatrix_width,0);
  last_row_mark.clear();
  last_row_mark.resize(Mymatrix_height,0);

  mode=0;  // mode 0 for col_mark modify, 1 for row_mark modify
  while(row_mark!=last_row_mark || col_mark!=last_col_mark){
    if(mode == 0){
      for(i=0; i<(int)row_mark.size(); i++){
        if(row_mark[i] != last_row_mark[i]){      // new marks in row_mark
          for(j=0; j<(int)Mymatrix[i].size(); j++){
            if(Mymatrix[i][j] == 0 && j != final_row_assignment[i]){
              col_mark[j]=1;
            }
          }
        }
      }
      last_row_mark= row_mark;
    }
    else{
      for(i=0; i<(int)col_mark.size(); i++){
        if(col_mark[i] != last_col_mark[i]){
          for(j=0; j<Mymatrix_height; j++){
            if(Mymatrix[j][i] == 0 && j == final_col_assignment[i]){
              row_mark[j]=1;
            }
          }
        }
      }
      last_col_mark=col_mark;
    }

    if(mode == 0){
      mode = 1;
    }
    else{
      mode = 0;
    }
  }

  return;
}

void Hungarian::DrawLines(){
    int i,j;

    Matrix_lines.clear();
    Matrix_lines.resize(Mymatrix_height);
    for(i=0;i<Mymatrix_width;i++)
      Matrix_lines[i].resize(Mymatrix_width,0);

    for(i=0; i<(int)row_mark.size(); i++){
      if(row_mark[i] == 0){
        for(j=0; j<(int)Matrix_lines[i].size(); j++)
          Matrix_lines[i][j]=1;
        Number_of_lines+=1;
      }
    }

    for(i=0; i<(int)col_mark.size(); i++){
      if(col_mark[i] == 1){
        for(j=0; j<(int)Matrix_lines.size(); j++){
          if(Matrix_lines[j][i]==1){
            Matrix_lines[j][i]=2;
          }
          else{
            Matrix_lines[j][i]=-1;
          }
        }
        Number_of_lines+=1;
      }
    }

    return;
}
