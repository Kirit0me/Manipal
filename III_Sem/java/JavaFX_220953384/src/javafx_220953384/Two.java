/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/javafx/FXMain.java to edit this template
 */
package javafx_220953384;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.FlowPane;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;

/**
 *
 * @author student
 */
public class Two extends Application {
    
    @Override
    public void start(Stage primaryStage) {    
        primaryStage.setTitle("Multiplication Table");

                FlowPane root = new FlowPane();
                root.setAlignment(Pos.CENTER);
                root.setHgap(10);
                root.setVgap(10);

                TextField numberField = new TextField();
                Button generateButton = new Button("Generate Multiplication Table");
                Label resultLabel = new Label();

                generateButton.setOnAction(event -> {
                    try {
                        int number = Integer.parseInt(numberField.getText());
                        StringBuilder table = new StringBuilder();
                        for (int i = 1; i <= 10; i++) {
                            table.append(number).append(" x ").append(i).append(" = ").append(number * i).append("\n");
                        }
                        resultLabel.setText(table.toString());
                    } catch (NumberFormatException e) {
                        resultLabel.setText("Please enter a valid number.");
                    }
                });

                root.getChildren().addAll(numberField, generateButton, resultLabel);

                Scene scene = new Scene(root, 400, 300);
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
