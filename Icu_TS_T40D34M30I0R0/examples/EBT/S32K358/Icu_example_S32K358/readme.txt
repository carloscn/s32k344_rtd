1. Example Description
    LED D39 - control with input in ICU-eMios pin through IcuSignalNotification function
    1.1 The application software functionality
        GPIO trigger will generate edges to ICU input pins. The interrupts will be generated for the ICU channels and the user's functions will be called, the user's functions will blink LED.
2. Installation steps
    2.1 Hardware installation
        2.1.1 Supported boards
            - Daughter Board: XS32K3X8CVB-Q289 PCB 53108 RevX3 SCH RevA1
            - Silicon: P32K358GVS 0P14E CTZF2233B (E5 sample)
        2.2.2 Connections
            A wire connection is required in Daughter Board:
                - J44.5 to J44.6
                - J13.1 to J13.2
                - J33.1(PTD1 - Gpio trigger) to J33.2(PTD0 - EMIOS_0_CH_2 Icu Channel)
                - J86.1(PTF21 - Gpio trigger) to J705.2 (LED D39)
        2.2.3 Debugger
            - The debugger must be connected to 20-pin JTAG Cortex Debug connector
    2.2 Software installation
        2.2.1 Tresos Project Installation
            The following procedure requires that the user has EB Tresos Studio installed and it is only needed for viewing, updating and generating the driver's configuration.
            Procedure:
                1. Make sure that all RTD plugins are already installed.
                2. Open Tresos Studio
                3. Import example application project
                    a. Click on "File" and select "Import"
                    b. Select "Existing Projects into Workspace" and click on "Next" button
                    c. Select "Select root directory" and click on "Browse"
                    d. Select the location of the [project] folder in the installed example application package folder. Do not copy the project into workspace unless you copy the whole example, otherwise compiling the files will not work as intended. 
                    e. Click on "Finish" button
        2.2.2 Example configuration
            The following procedure requires that the user has EB Tresos Studio installed and the toolchains versions specified in the Release Notes.
            The toolchain that will be used needs to be installed for correct operation and the path to the installation location shall be added into the system environment variable(s):
            - TRESOS_DIR the installation path of Electrobit Tresos (used for generating the project from command line)
                Ex: TRESOS_DIR = C:/EB/tresos29.0.0
            - GCC_DIR The path to the GCC installation dir
                Ex: GCC_DIR = C:/build_tools/gcc_v10.2/gcc-10.2-arm32-eabi
            - PLUGINS_DIR The path to the RTD plugins directory 
                Ex: PLUGINS_DIR = C:/NXP/SW32_RTD/eclipse/plugins
            - T32_DIR The path to the T32 directory
                Ex: T32_DIR = C:/T32

            Procedure:
                1. Open project_parameters.mk file in a text editor and update the variables mentioned above with the correct paths
3. Building the example application
    For using the command line a make tool needs to be installed on your machine. For full functionality from command line sed is also required.
    3.1 Generating the Tresos project
        Procedure:
            1. Open the Windows command prompt window
            2. Change the current directory to the example application folder
            3. To generate the Tresos project of the example, execute the following command to build: make generate
            4. The output files of the generation shall be generated in the /generate subdirectory
    3.2 Compiling the application
        Procedure:
            1. Open the Windows command prompt window
            2. Change the current directory to the example application folder
            3. To build the example, execute the following command to build: make build
            4. The object files and linker output file (main.elf) shall be generated in the /out subdirectory
    3.3 Running the application on the board
        For executing the script in a T32 window already you can run the run.cmm script as is.
        To execute the example application from your command line execute make run. Note: to be able to run this command a sed package needs to be installed on your machine as it is used for dynamically updating some paths in the files that are used by this step.
    3.4 Modifying the configuration in Tresos and generating the code
        Users may change the application configuration according to their needs.
        Procedure:
            1. Open the EB Tresos Studio GUI
            2. Open previously imported Example Application project
            3. Use the Tresos Studio GUI to modify configuration parameter values and save the changes.
            4. Select the Example Application project and click on "Generate" button to generate the configuration files.
