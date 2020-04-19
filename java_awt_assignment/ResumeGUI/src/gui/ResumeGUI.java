package gui;
import java.awt.*;
import java.awt.event.*;
import java.io.*;

public class ResumeGUI extends Frame implements ActionListener{
	
	private TextField name;
	private TextField email;
	private TextField contactNo;
	private TextField dob;
	private TextField education;
	private TextField workEx;
	private TextField skill;
	private TextField project;
	private TextField activity;
	
	public ResumeGUI() {
		
		setSize(900, 900);
		setLayout(new GridLayout(21, 0, 5, 5));
		addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent windowEvent) {
				System.exit(0);
			}
		});
		
		name = new TextField();
		email = new TextField();
		contactNo = new TextField();
		dob = new TextField();
		education = new TextField();
		workEx = new TextField();
		skill = new TextField();
		project = new TextField();
		activity = new TextField();
		
		Label introLabel = new Label("-------Welcome to Resume Builder!-------");
		Label nameLabel = new Label("Name: ");
		Label emailLabel = new Label("E-Mail: ");
		Label contactLabel = new Label("Contact No: ");
		Label dobLabel = new Label("Date of Birth: ");
		Label eduLabel = new Label("Education: ");
		Label workLabel = new Label("Work Experience: ");
		Label skillLabel = new Label("Skills: ");
		Label projLabel = new Label("Projects: ");
		Label activityLabel = new Label("Extra Curricular Activities: ");
		
		Button reset = new Button("Reset!");
		Button submit = new Button("Submit!");
		
		nameLabel.setAlignment(Label.CENTER);
		emailLabel.setAlignment(Label.CENTER);
		contactLabel.setAlignment(Label.CENTER);
		dobLabel.setAlignment(Label.CENTER);
		eduLabel.setAlignment(Label.CENTER);
		workLabel.setAlignment(Label.CENTER);
		skillLabel.setAlignment(Label.CENTER);
		projLabel.setAlignment(Label.CENTER);
		activityLabel.setAlignment(Label.CENTER);
		introLabel.setAlignment(Label.CENTER);
		
		add(introLabel);
		
		add(nameLabel);
		add(name);

		add(emailLabel);
		add(email);
		
		add(contactLabel);
		add(contactNo);
		
		add(dobLabel);
		add(dob);
		
		add(eduLabel);
		add(education);
		
		add(workLabel);
		add(workEx);
		
		add(skillLabel);
		add(skill);
		
		add(projLabel);
		add(project);
		
		add(activityLabel);
		add(activity);
		
		add(reset);
		add(submit);
		
		reset.setActionCommand("Reset");
		submit.setActionCommand("Submit");
		reset.addActionListener(this);
		submit.addActionListener(this);
		
		setVisible(true);
	}
		
		public void actionPerformed(ActionEvent e) {
			String cmd = e.getActionCommand();
			System.out.print(cmd);
			if(cmd.equals("Reset")) {
				name.setText("");
				email.setText("");
				contactNo.setText("");
				dob.setText("");
				education.setText("");
				workEx.setText("");
				skill.setText("");
				project.setText("");
				activity.setText("");
			}
			
			else if(cmd.equals("Submit")) {
				try {
					FileWriter fr = new FileWriter("resume.txt", true);
					
					int i = 0;
					String s;
					
					s = name.getText();
					fr.write("----------NAME----------\n");
					for(i=0; i<s.length(); i++)
						fr.write(s.charAt(i));
					fr.write("\n");

					s = email.getText();
					fr.write("-----------E-MAIL----------\n");
					for(i=0; i<s.length(); i++)
						fr.write(s.charAt(i));
					fr.write("\n");

					s = contactNo.getText();
					fr.write("----------CONTACT----------\n");
					for(i=0; i<s.length(); i++)
						fr.write(s.charAt(i));
					fr.write("\n");

					s = dob.getText();
					fr.write("----------DATE OF BIRTH----------\n");
					for(i=0; i<s.length(); i++)
						fr.write(s.charAt(i));
					fr.write("\n");

					s = education.getText();
					fr.write("----------EDUCATION----------\n");
					for(i=0; i<s.length(); i++)
						fr.write(s.charAt(i));
					fr.write("\n");

					s = workEx.getText();
					fr.write("----------WORK EXPERIENCE----------\n");
					for(i=0; i<s.length(); i++)
						fr.write(s.charAt(i));
					fr.write("\n");

					s = skill.getText();
					fr.write("----------SKILLS----------\n");
					for(i=0; i<s.length(); i++)
						fr.write(s.charAt(i));
					fr.write("\n");

					s = project.getText();
					fr.write("----------PROJECTS----------\n");
					for(i=0; i<s.length(); i++)
						fr.write(s.charAt(i));
					fr.write("\n");

					s = activity.getText();
					fr.write("----------EXTRA CURRICULAR ACTIVITIES----------\n");
					for(i=0; i<s.length(); i++)
						fr.write(s.charAt(i));
					fr.write("\n\n----------------------------------------\n\n");
					
					fr.close();
					System.out.println("\nData Successfully Added");
				}
				
				catch(Exception e1) {
					System.err.println(e1);
				}
			}
			
		}

	public static void main(String[] args) {
		
		new ResumeGUI();

	}

}
