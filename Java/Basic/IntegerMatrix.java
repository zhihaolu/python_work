import java.util.*;
 
class Matrix{
	int row , column;
	double[][] matrix;
	//���캯��
	Matrix(double[][] matrix){
		this.row = matrix.length;
		this.column = matrix[0].length;
		this.matrix = new double[this.row][this.column];
		for(int i = 0 ; i < this.row ; i++)
			for(int j = 0 ; j < this.column ; j++)
				this.matrix[i][j] = matrix[i][j];
	}
	//����ӷ�
	Matrix add(Matrix mat2){
		double[][] add_result = new double[this.row][this.column];
		for(int i = 0 ; i < this.row ; i++)
			for(int j = 0 ; j < this.column ; j++)
				add_result[i][j] = this.matrix[i][j]+mat2.matrix[i][j];
		return new Matrix(add_result);
	}
	//�������
	Matrix minus(Matrix mat2){
		double[][] add_result = new double[this.row][mat2.column];
		for(int i = 0 ; i < this.row ; i++)
			for(int j = 0 ; j < this.column ; j++)
				add_result[i][j] = this.matrix[i][j]-mat2.matrix[i][j];
		return new Matrix(add_result);
	}
	//����˷�
	Matrix multiply(Matrix mat2){
		double[][] multiply_result = new double[this.row][mat2.column];
		for(int i = 0 ; i < this.row ; i++ )
			for(int j = 0 ; j < mat2.column ; j++)
				for(int k = 0 ; k < mat2.row ; k++ ){
					multiply_result[i][j] += this.matrix[i][k]*mat2.matrix[k][j];  
				}
		return new Matrix(multiply_result);
	}
	//��ӡ����
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
		
		//��һ������
		System.out.println("�����һ�������������������");
		row = sc.nextInt();
		column = sc.nextInt();
		double[][] m = new double[row][column];
		System.out.println("���õ�һ������");
		for(int i = 0 ; i < row ; i++)
			for(int j = 0 ; j < column ; j++)
				m[i][j] = sc.nextDouble();
		Matrix matrix1 = new Matrix(m);
		//�ڶ�������
		System.out.println("����ڶ��������������������");
		row = sc.nextInt();
		column = sc.nextInt();
		m = new double[row][column];
		System.out.println("���õڶ�������");
		for(int i = 0 ; i < row ; i++)
			for(int j = 0 ; j < column ; j++)
				m[i][j] = sc.nextDouble();
		Matrix matrix2 = new Matrix(m);
		//ѡ��Ҫ���е�����
		while(true){
			System.out.println("ѡ��Ҫ���е�����(+/-/*)��");
			select = sc.next();
			if(select.equals("+")){
				if(matrix1.row != matrix2.row || matrix1.column != matrix2.column){
					System.out.println("����!�����Ͼ������㷨��!");
				}
				else{
					Matrix matrix3 = matrix1.add(matrix2);
					System.out.println("������� =");
					matrix3.print();
				}
			}
			if(select.equals("-")){
				if(matrix1.row != matrix2.row || matrix1.column != matrix2.column){
					System.out.println("����!�����Ͼ������㷨��!");
				}
				else{
					Matrix matrix3 = matrix1.minus(matrix2);
					System.out.println("������� =");
					matrix3.print();
				}
			}
			if(select.equals("*")){
				if(matrix1.column != matrix2.row){
					System.out.println("����!�����Ͼ������㷨��!");
				}
				else
				{
					Matrix matrix3 = matrix1.multiply(matrix2);
					System.out.println("������� =");
					matrix3.print();
				}
			}
			System.out.println("ѡ����������?(Y/N)");
			judge = sc.next();
			if(judge.equals("Y")|judge.equals("y"))
				continue;
			else
				break;
		}
		sc.close();
 
	}
 
}
