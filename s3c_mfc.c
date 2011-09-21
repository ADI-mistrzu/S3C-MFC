/*
 * s3c_mfc.c  --  MFC
 *
 * Copyright 2011 Adrian Chmiel <adi-mistrzu@o2.pl>
 *
 * This file is subject to the terms and conditions of the GNU General Public
 * License.  See the file COPYING in the main directory of this archive for
 * more details.
 *
 */

#include <linux/clk.h>
#include <linux/delay.h>
#include <linux/interrupt.h>
#include <linux/io.h>
#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/sched.h>
#include <linux/slab.h>
#include <linux/version.h>
#include <linux/videodev2.h>
#include <linux/workqueue.h>
#include <media/videobuf2-core.h>

#define     S3C_MFC_NAME		"S3C-MFC"

/////////////////////////////////////////////////////////////////////////////////


static int s3c_mfc_suspend( void )  // Sunpend MFC
{
    return 0;
}

static int s3c_mfc_resume( void )   // Resume MFC
{
    return 0;
}

static int s3c_mfc_runtime_suspend( void )
{
    return 0;
}

static int s3c_mfc_runtime_suspend( void )
{
    return 0;
}

static int __devinit s3c_mfc_probe( void ) // MFC probe function
{
    return 0;
}

static __devexit s3c_mfc_remove( void ) // Remove driver
{
    return 0;
}

static const struct dev_pm_ops s3c_mfc_pm = {   // Power Manager
	SET_SYSTEM_SLEEP_PM_OPS( s3c_mfc_suspend, s3c_mfc_resume )
	SET_RUNTIME_PM_OPS( s3c_mfc_runtime_suspend, s3c_mfc_runtime_resume, NULL )
};

/////////////////////////////////////////////////////////////////////////////////

static struct platform_driver s3c_mfc_pdrv = {  //
	.probe	= s3c_mfc_probe,
	.remove	= __devexit_p( s3c_mfc_remove ),
	.driver	= {
		.name	= S3C_MFC_NAME,
		.owner	= THIS_MODULE,
		.pm     = &s3c_mfc_pm
	},
};

/////////////////////////////////////////////////////////////////////////////////

static int __init s3c_mfc_init( void )      // Init function
{
	int err;

	pr_info( "S3C MFC Driver, Powered by Adrian Chmiel\n" );
	err = platform_driver_register( &s3c_mfc_pdrv );
	if( err )
		pr_err( "Platform device registration failed.\n" );
	return err;
}

static void __devexit s3c_mfc_exit( void )  // Exit function
{
	platform_driver_unregister( &s3c_mfc_pdrv );
}

/////////////////////////////////////////////////////////////////////////////////

module_init(s3c_mfc_init);  // initial module
module_exit(s3c_mfc_exit);  // remount module

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Adrian Chmiel <adi-mistrzu@o2.pl>");
MODULE_DESCRIPTION("S3C Multi Format Codec driver");
