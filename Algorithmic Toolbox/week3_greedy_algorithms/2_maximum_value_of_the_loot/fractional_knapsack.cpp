#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

double get_optimal_value(int n,int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
	vector<double> weightspervalue(n);	
	for (int i = 0; i < n; i++)
	weightspervalue[i]=(double)values[i]/weights[i];
while(capacity>0){
int i=distance(weightspervalue.begin(),max_element(weightspervalue.begin(),weightspervalue.end()));

	if(weights[i]<capacity&&weightspervalue[i]!=0)
	{
		value=value+(double)values[i];
		weightspervalue[i]=0;
		capacity=capacity-weights[i];
	}
	else if(weights[i]>=capacity&&weightspervalue[i]!=0)	
	{
	 value=value+(double)(weightspervalue[i]*capacity);
		capacity=0;
	}
	else
	return value;
	
}
return value;
}
int main() {
  int n;
  int capacity;
  cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(n,capacity, weights, values);

  cout.precision(10);
  cout << (double)optimal_value << std::endl;
  return 0;
}
