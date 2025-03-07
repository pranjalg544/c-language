#include <stdio.h>
#include <stdlib.h>
#define maxTerms 20
#define maxDocs 20

struct TermDocumentMatrix {
    int terms;
    int documents;
    int value[maxTerms][maxDocs];
};

struct TermDocumentMatrix CreateTermDocumentMatrix(int ntrms, int ndocs){
    struct TermDocumentMatrix tdm;
    tdm.terms = ntrms;
    tdm.documents = ndocs;
    for (int i = 0; i < ntrms; i++) {
        for (int j = 0; j < ndocs; j++) { 
            tdm.value[i][j] = 0;
        }
    }
    return tdm;
}

void UpdateTermFrequency(struct TermDocumentMatrix *tdm, int term ,int document , int val){
    (*tdm).value[term - 1][document - 1] = val;
}

void print(struct TermDocumentMatrix tdm){
    for(int i=0; i < tdm.terms ; i++ ){
        for(int j=0; j < tdm.documents ; j++ ){
            printf("%d ", tdm.value[i][j]);
        } printf("\n");
    } printf("\n");
}

int GetTermFrequency(struct TermDocumentMatrix *tdm, int term, int document) {
    return (*tdm).value[term][document];
}

int GetDocumentFrequency(struct TermDocumentMatrix *tdm, int term) {
    int count = 0;
    for (int i = 0; i < (*tdm).documents; i++) {
        if ((*tdm).value[term][i] > 0) {
            count++;
        }
    }
    return count;
}

int GetTotalTermsInDocument(struct TermDocumentMatrix *tdm, int document) {
    int count = 0;
    for (int i = 0; i < (*tdm).terms; i++) {
        if ((*tdm).value[i][document] > 0) {
            count++;
        }
    }
    return count;
}

void ToSparseMatrix(struct TermDocumentMatrix *tdm, int sparse_matrix[3][maxTerms * maxDocs]){
    int k = 0;
    for (int i = 0; i < (*tdm).terms; i++) {
        for (int j = 0; j < (*tdm).documents; j++){
            if ((*tdm).value[i][j] != 0){
                sparse_matrix[0][k] = i;
                sparse_matrix[1][k] = j;
                sparse_matrix[2][k] = (*tdm).value[i][j];
                k++;
            }
        }
    }
}

int main(){
    
    struct TermDocumentMatrix tdm = CreateTermDocumentMatrix(5,5);
    print(tdm);

    UpdateTermFrequency(&tdm, 1, 4, 2);
    UpdateTermFrequency(&tdm, 3, 3, 4);
    UpdateTermFrequency(&tdm, 5, 5, 6);
    print(tdm);

    printf("Document frequency for Term 1: %d\n", GetDocumentFrequency(&tdm, 4));
    printf("Total terms in Document 1: %d\n", GetTotalTermsInDocument(&tdm, 3));

    int sparse_matrix[3][maxTerms * maxDocs];
    ToSparseMatrix(&tdm, sparse_matrix);

    return 0;
}