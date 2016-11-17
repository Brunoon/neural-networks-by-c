# neural-networks-by-c
a neural networks implemented by c from scratch

# tutorial
&emsp;&emsp;First you should unzip the .gz data files,then execute following command.

```
gcc test_matrix.c matrix.c -o test_matrix -lm
./test_matrix

gcc test_reader.c mnist_reader.c matrix.c -o test_reader -lm
./test_reader

gcc nn.c matrix.c mnist_reader.c -o nn -lm
./nn
```
