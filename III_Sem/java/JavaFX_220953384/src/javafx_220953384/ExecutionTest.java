/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/javafx/FXMain.java to edit this template
 */
package javafx_220953384;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.HPos;
import javafx.geometry.Insets;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.RadioButton;
import javafx.scene.control.ToggleGroup;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;

/**
 *
 * @author student
 */
public class ExecutionTest extends Application {
    
    @Override
    public void start(Stage primaryStage) {
        GridPane gridPane = new GridPane();
        gridPane.setPadding(new Insets(10));
        gridPane.setHgap(10);
        gridPane.setVgap(10);

        Label label = new Label("Prabhav 220953384");

        ToggleGroup toggleGroup = new ToggleGroup();

        RadioButton radioButton1 = new RadioButton("Option 1");
        radioButton1.setToggleGroup(toggleGroup);
        RadioButton radioButton2 = new RadioButton("Option 2");
        radioButton2.setToggleGroup(toggleGroup);
        RadioButton radioButton3 = new RadioButton("Option 3");
        radioButton3.setToggleGroup(toggleGroup);
        RadioButton radioButton4 = new RadioButton("Option 4");
        radioButton4.setToggleGroup(toggleGroup);

        Button b1 = new Button("Button 1");
        Button b2 = new Button("Button 2");
        Button b3 = new Button("Button 3");
        Button b4 = new Button("Button 4");
        
        radioButton1.setOnAction(event -> label.setText(" Option 1"));
        radioButton2.setOnAction(event -> label.setText(" Option 2"));
        radioButton3.setOnAction(event -> label.setText(" Option 3"));
        radioButton4.setOnAction(event -> label.setText(" Option 4"));

        GridPane.setConstraints(label, 1, 1);
        GridPane.setConstraints(radioButton1, 0, 0);
        GridPane.setConstraints(radioButton2, 0, 2);
        GridPane.setConstraints(radioButton3, 2, 2);
        GridPane.setConstraints(radioButton4, 2, 0);
        GridPane.setConstraints(b1, 0, 1);
        GridPane.setConstraints(b2, 1, 0);
        GridPane.setConstraints(b3, 2, 1);
        GridPane.setConstraints(b4, 1, 2);

        gridPane.getChildren().addAll(label, radioButton1, radioButton2, radioButton3, radioButton4, b1, b2, b3, b4);

        Scene scene = new Scene(gridPane, 400, 200);

        primaryStage.setTitle("Lab Execution Test");
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
