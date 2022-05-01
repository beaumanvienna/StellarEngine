//
// Created by lukas on 23.04.22.
//

#ifndef VENDOR_CONTENTBROWSERPANEL_H
#define VENDOR_CONTENTBROWSERPANEL_H

#include <filesystem>
#include "../../Engine/Graphics/texture.h"
#include "../../Engine/Graphics/descriptors.h"

namespace Engine {

    class ContentBrowserPanel
    {
    public:
        ContentBrowserPanel();

        void OnImGuiRender();
    private:
        std::filesystem::path m_CurrentDirectory;
        void FileTree(const std::filesystem::path& path);

        std::unique_ptr<Texture> m_FileIcon;
        std::unique_ptr<Texture> m_DirectoryIcon;
    };

}


#endif //VENDOR_CONTENTBROWSERPANEL_H