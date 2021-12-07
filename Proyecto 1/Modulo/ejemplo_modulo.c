//Header obligatorio de todos los modulos
#include <linux/module.h>
//Header para usar KERN_INFO
#include <linux/kernel.h>

//Header para los macros module_init y module_exit
#include <linux/init.h>
//Header necesario porque se usara proc_fs
#include <linux/proc_fs.h>
/* for copy_from_user */
#include <asm/uaccess.h>	
/* Header para usar la lib seq_file y manejar el archivo en /proc*/
#include <linux/seq_file.h>

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Ejemplo creacion de modulo en Linux, Laboratorio Sistemas Operativos 1");
MODULE_AUTHOR("Bernald Renato Paxtor Peren");


static int escribir_archivo(struct seq_file *archivo, void *v)
{   

    seq_printf(archivo, "*********************************************\n");
    seq_printf(archivo, "*********************************************\n");
    seq_printf(archivo, "**    LABORATORIO SISTEMAS OPERATIVOS 1    **\n");
    seq_printf(archivo, "**       EJEMPLO CREACION DE MODULOS       **\n");
    seq_printf(archivo, "**       BERNALD RENATO PAXTOR PEREN       **\n");
    seq_printf(archivo, "*********************************************\n");
    seq_printf(archivo, "*********************************************\n");
    return 0;
}


static int al_abrir(struct inode *inode, struct file *file)
{
    return single_open(file, escribir_archivo, NULL);
}

static struct proc_ops operaciones =
{
    .proc_open = al_abrir,
    .proc_read = seq_read
};


static int _insert(void)
{
    proc_create("ejemplo_modulo", 0, NULL, &operaciones);
    printk(KERN_INFO "Mensaje al insertar modulo, Laboratorio SO 1\n");
    return 0;
}

static void _remove(void)
{
    remove_proc_entry("ejemplo_modulo", NULL);
    printk(KERN_INFO "Mensaje al remover modulo, Laboratorio SO 1\n");
}

module_init(_insert);
module_exit(_remove);