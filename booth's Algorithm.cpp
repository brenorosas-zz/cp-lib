//Retorna a posição 0-based do inicio da menor rotação de uma string (lexicografica);
int least_rotation(string s){
	s+=s;
	vector<int>f(s.size(),-1);
	int k = 0;
	for(int j=1;j<s.size();j++){
		char sj = s[j];
		int i = f[j-k-1];
		while(i!=-1 and sj != s[k+i+1]){
			if(sj < s[k+i+1]){
				k = j - i - 1;
			}
			i = f[i];
		}
		if(sj != s[k+i+1]){
			if(sj < s[k]){
				k = j;
			}
			f[j - k] = -1;
		}
		else{
			f[j - k] = i+1;
		}
	}
	return k;
}