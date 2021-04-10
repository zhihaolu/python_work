import java.util.*;
 
class Matrix{
	int row , column;
	double[][] matrix;
	//构造函数
	Matrix(double[][] matrix){
		this.row = matrix.length;
		this.column = matrix[0].length;
		this.matrix = new double[this.row][this.column];
		for(int i = 0 ; i < this.row ; i++)
			for(int j = 0 ; j < this.column ; j++)
				this.matrix[i][j] = matrix[i][j];
	}
	//矩阵加法
	Matrix add(Matrix mat2){
		double[][] add_result = new double[this.row][this.column];
		for(int i = 0 ; i < this.row ; i++)
			for(int j = 0 ; j < this.column ; j++)
				add_result[i][j] = this.matrix[i][j]+mat2.matrix[i][j];
		return new Matrix(add_result);
	}
	//矩阵减法
	Matrix minus(Matrix mat2){
		double[][] add_result = new double[this.row][mat2.column];
		for(int i = 0 ; i < this.row ; i++)
			for(int j = 0 ; j < this.column ; j++)
				add_result[i][j] = this.matrix[i][j]-mat2.matrix[i][j];
		return new Matrix(add_result);
	}
	//矩阵乘法
	Matrix multiply(Matrix mat2){
		double[][] multiply_result = new double[this.row][mat2.column];
		for(int i = 0 ; i < this.row ; i++ )
			for(int j = 0 ; j < mat2.column ; j++)
				for(int k = 0 ; k < mat2.row ; k++ ){
					multiply_result[i][j] += this.matrix[i][k]*mat2.matrix[k][j];  
				}
		return new Matrix(multiply_result);
	}
	//打印函数
	void print(){
		for(int i = 0 ; i < this.row ; i++){
			for(int j = 0 ; j < this.column ; j++){
				System.out.print(this.matrix[i][j] + " ");	
			}
			System.out.println();
		}
	}
}
 
 
 
public class IntegerMatrix {
 
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int row , column;
		String select , judge;
		
		//第一个矩阵
		System.out.println("输入第一个矩阵的行数和列数：");
		row = sc.nextInt();
		column = sc.nextInt();
		double[][] m = new double[row][column];
		System.out.println("设置第一个矩阵：");
		for(int i = 0 ; i < row ; i++)
			for(int j = 0 ; j < column ; j++)
				m[i][j] = sc.nextDouble();
		Matrix matrix1 = new Matrix(m);
		//第二个矩阵
		System.out.println("输入第二个矩阵的行数和列数：");
		row = sc.nextInt();
		column = sc.nextInt();
		m = new double[row][column];
		System.out.println("设置第二个矩阵：");
		for(int i = 0 ; i < row ; i++)
			for(int j = 0 ; j < column ; j++)
				m[i][j] = sc.nextDouble();
		Matrix matrix2 = new Matrix(m);
		//选择要进行的运算
		while(true){
			System.out.println("选择要进行的运算(+/-/*)：");
			select = sc.next();
			if(select.equals("+")){
				if(matrix1.row != matrix2.row || matrix1.column != matrix2.column){
					System.out.println("错误!不符合矩阵运算法则!");
				}
				else{
					Matrix matrix3 = matrix1.add(matrix2);
					System.out.println("矩阵相加 =");
					matrix3.print();
				}
			}
			if(select.equals("-")){
				if(matrix1.row != matrix2.row || matrix1.column != matrix2.column){
					System.out.println("错误!不符合矩阵运算法则!");
				}
				else{
					Matrix matrix3 = matrix1.minus(matrix2);
					System.out.println("矩阵相减 =");
					matrix3.print();
				}
			}
			if(select.equals("*")){
				if(matrix1.column != matrix2.row){
					System.out.println("错误!不符合矩阵运算法则!");
				}
				else
				{
					Matrix matrix3 = matrix1.multiply(matrix2);
					System.out.println("矩阵相乘 =");
					matrix3.print();
				}
			}
			System.out.println("选择其它运算?(Y/N)");
			judge = sc.next();
			if(judge.equals("Y")|judge.equals("y"))
				continue;
			else
				break;
		}
		sc.close();
 
	}
 
}
