void construct_lps(string &pat, vector <int> & lps){
    int len = 0;

    lps[0] = 0;

    int i = 1;

    while(i < pat.length()){
        if(pat[i] == pat[len]){
            len++; 
            lps[i] = len;
            i++;
        }

        else{
            if(len != 0){
                len = lps[len - 1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }

}

vector <int> search(string &txt, string &pat){
    int n = txt.length(), m = pat.length();

    vector <int> lps(m), res;
    construct_lps(pat, lps);

    int i = 0, j = 0;

    while(i < n){
        if(txt[i] == pat[j]){
            i++; j++;

            if(j == m){
                res.push_back(i - j);

                j = lps[j - 1];
            }
        }

        else{
            if(j != 0){
                j = lps[j - 1];
            }
            else{
                i++;
            }
        }
    }

    return res;

}
