import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.control.Button;

public class App14_1 extends Application {
    @Override   //强调必须覆盖下面这个父类中的方法
    public void start(Stage primaryStage){
        Button bt = new Butrton("i'am button");
        Scene scene = new Scene(bt,210,80);
        primaryStage.setTile("my javafx windows ");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    public static void main(String[] args) {
        Application.launch(args);
    }
}