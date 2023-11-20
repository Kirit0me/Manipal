/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/javafx/FXMain.java to edit this template
 */
package javafx_220953384;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.FlowPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.StackPane;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

/**
 *
 * @author student
 */
public class JavaFX_220953384 extends Application {
    
    @Override
    public void start(Stage primaryStage) {
        
        Button add = new Button();
        add.setText("Add");
        Button sub = new Button();
        sub.setText("Subtract");
        
        Label l1=new Label("First Number");
        Label l2=new Label("Second Number");
        Label l3=new Label("Result");
        
        TextField t1 = new TextField();
        TextField t2 = new TextField();
        TextField t3 = new TextField();
        
        HBox h1 = new HBox();
        h1.getChildren().add(l1);
        h1.getChildren().add(t1);
        
        HBox h2 = new HBox();        
        h2.getChildren().add(l2);
        h2.getChildren().add(t2);
        
        HBox h3 = new HBox();        
        h3.getChildren().add(l3);
        h3.getChildren().add(t3);
        
        HBox h4 = new HBox();        
        h4.getChildren().add(add);
        h4.getChildren().add(sub);
        
        VBox v1 = new VBox();        
        v1.getChildren().add(h1);
        v1.getChildren().add(h2);
        v1.getChildren().add(h3);
        v1.getChildren().add(h4);
        
        add.setOnAction(event -> {
            try {
                double num1 = Double.parseDouble(t1.getText());
                double num2 = Double.parseDouble(t2.getText());
                double result = num1 + num2;
                t3.setText(String.valueOf(result));
            } catch (NumberFormatException e) {
                t3.setText("Invalid Input");
            }
        });
        sub.setOnAction(event -> {
            try {
                double num1 = Double.parseDouble(t1.getText());
                double num2 = Double.parseDouble(t2.getText());
                double result = num1 - num2;
                t3.setText(String.valueOf(result));
            } catch (NumberFormatException e) {
                t3.setText("Invalid Input");
            }
        });
        
        FlowPane root = new FlowPane();
        root.getChildren().add(v1);
        
        Scene scene = new Scene(root, 300, 250);
        
        primaryStage.setTitle("CatuLator");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        launch(args);
    }
    
}
