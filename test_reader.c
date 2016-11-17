#include <stdio.h>
#include "mnist_reader.h"
#include "matrix.h"


int main(void) {
    matrix *train_images[60000];
    char *fileimages = "/home/kinny/Study/demo/train_images.txt";
    readImageDataAsVectorArray(fileimages, &train_images, 60000, 28*28);

    int i, j;
    double elem;
    for (i = 0; i < 10; i++) {
        for (j = 1; j <= 28*28; j++) {
            getElement(train_images[i], j, 1, &elem);
            if (j % 28 == 1) printf("\n");
            printf("%6.2f ", elem);
        }
        printf("\n");
    }

    printf("\n");
    matrix *train_labels[60000];
    char *filelabels = "/home/kinny/Study/demo/train_labels.txt";
    readLabelDataAsVectorArray(filelabels, &train_labels, 60000, 10);

    for (j = 1; j <= 10; j++) {
        for (i = 0; i < 10; i++) {
            getElement(train_labels[i], j, 1, &elem);
            printf("%6.2f ", elem);
        }
        printf("\n");
    }

    for (i = 0; i < 60000; i++) {
        deleteMatrix(train_images[i]);
        deleteMatrix(train_labels[i]);
    }

    printf("-----------------------------------------------------------------------------------\n");
    matrix *test_images[10000];
    char *testfileimages = "/home/kinny/Study/demo/test_images.txt";
    readImageDataAsVectorArray(testfileimages, &test_images, 10000, 28*28);

    for (i = 0; i < 10; i++) {
        for (j = 1; j <= 28*28; j++) {
            getElement(test_images[i], j, 1, &elem);
            if (j % 28 == 1) printf("\n");
            printf("%6.2f ", elem);
        }
        printf("\n");
    }

    printf("\n");
    matrix *test_labels[10000];
    char *testfilelabels = "/home/kinny/Study/demo/test_labels.txt";
    readLabelDataAsVectorArray(testfilelabels, &test_labels, 10000, 10);

    for (j = 1; j <= 10; j++) {
        for (i = 0; i < 10; i++) {
            getElement(test_labels[i], j, 1, &elem);
            printf("%6.2f ", elem);
        }
        printf("\n");
    }

    for (i = 0; i < 10000; i++) {
        deleteMatrix(test_images[i]);
        deleteMatrix(test_labels[i]);
    }
    return 0;
}
