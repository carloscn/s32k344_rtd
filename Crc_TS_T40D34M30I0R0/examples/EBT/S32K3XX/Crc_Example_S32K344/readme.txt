1. Example Description
    This application demonstrates the usage of a subset of Real Time Drivers that are included in this release.
    The application includes an EB Tresos project that configures the Base, Crc, Mcu, and Resource drivers.
    1.1 The application software functionality
            - Mcu_Init, Mcu_InitClock, Mcu_DistributePllClock, Mcu_SetMode
                Initialize the clock sources, the clock tree and to configure the clock gating of the peripherals.
                The clock configuration that is used will enable and use the PLL as source clock.
            - Mcl_Init
                Initialize the Mcl Driver: Initialize the DMA Logic Instance and DMA Logic Channel 0
                Logic Channel 0 is configured in EB Tresos to run in Normal Transfer Mode.
            - Crc_Init
                Initialize the Crc driver
            - Verify that the Crc result returned corresponds to the expected value. If the CRC result is the expected one, then the returned status is TRUE.
2. Installation steps
    2.1 Hardware installation
        2.1.1 Supported boards
            - EVB: S32K3X4EVB-Q257 47827 PCB RevX1 SCH RevA. Silicon: P32K344EHVMMS 0P55A CTSK2038A 
            - EVB: S32K3X4EVB-Q172 51972 PCB RevA SCH RevA. Silicon: P32K344EHVPBS 1P55A CTZX2128B
        2.1.2 Connections
            Powered board through power Adapter 12V
        2.1.3 Debugger
            - The debugger must be connected to a J12 - 20 pin JTAG Cortex Debug connector(172)/ J365 - 20 pin JTAG Cortex Debug connector(257)
    2.2 Software installation
        2.2.1 Tresos Project Installation
            The following procedure requires that the user has EB Tresos Studio installed and it is only needed for viewing, updating and generating the driver's configuration.
            Procedure:
                1. Make sure that all RTD plugins are already installed in the Tresos Studio plugins directory
                2. Open Tresos Studio
                3. Import example application project
                    a. Click on "File" and select "Import"
                    b. Select "Existing Projects into Workspace" and click on "Next" button
                    c. Select "Select root directory" and click on "Browse"
                    d. Select the location of the [project] folder in the installed example application package folder
                    e. Optional* - Select "Copy projects into workspace"
                    f. Click on "Finish" button
        2.2.2 Example configuration
            The following procedure requires that the user has EB Tresos Studio installed and the toolchains versions specified in the Release Notes.
            The toolchain that will be used needs to be installed for correct operation and the path to the installation location shall be added into the system environment variable(s):
            - TRESOS_DIR the installation path of Electrobit Tresos (used for generating the project from command line)
                Ex: TRESOS_DIR = C:/EB/tresos27
            - GCC_DIR The path to the GCC installation dir
                Ex: GCC_DIR = C:/NXP/S32DS.3.3/S32DS/build_tools/gcc_v9.2/gcc-9.2-arm32-eabi
            - T32_DIR The path to the T32 installation dir
                Ex: T32_DIR = D:/t32/trace32_n_2022_10_000152557_nxp_internal_conf_20221006124214
            - PLUGINS_DIR The path to the RTD plugins directory
                Ex: PLUGINS_DIR = C:/NXP/SW32_RTD/eclipse/plugins
            Procedure:
                1. Open project_parameters.mk file in a text editor and update the variables mentioned above with the correct paths
3. Building the example application
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
        To execute the example application from your command line execute make run. For executing the script in a T32 window already open the paths from run.cmm need to be changed relative to the debug folder instead of the example root folder.
    3.4 Modifying the configuration in Tresos and generating the code
        Users may change the application configuration according to their needs.
        Procedure:
            1. Open the EB Tresos Studio GUI
            2. Open previously imported Example Application project
            3. Use the Tresos Studio GUI to modify configuration parameter values and save the changes.
            4. Select the Example Application project and click on "Generate" button to generate the configuration files.
