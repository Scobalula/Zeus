#include "pch.h"
#include "BSPConverter.h"

void BSPConverter::Load(const std::string& Path, Settings& settings)
{
    Reader.Open(Path);

    Header = Reader.ReadStruct<D3DBSPHeader>();

#if _DEBUG
    PLX::Printer::WriteLineHeader("DEBUG", "Magic: 0x%llx", Header.Magic);
    PLX::Printer::WriteLineHeader("DEBUG", "Version: 0x%llx", Header.Version);
    PLX::Printer::WriteLineHeader("DEBUG", "Lump Count: 0x%llx", Header.LumpCount);
#endif

    if (Header.Magic != Magic)
        throw std::exception("Invalid BSP File Magic, expecting IBSP");
    if(Header.Version != Version)
        throw std::exception("Invalid BSP File Version, expecting 0x5F");

    LoadLumps();
}

void BSPConverter::Save(const std::string& folder, const std::string& name, Settings& settings)
{
    std::filesystem::create_directories(folder);

    if (settings.GetSettingValue("ToXME", "Yes") == "Yes")
        ToXME(folder + "\\" + name + ".xmodel_export", settings);
    if (settings.GetSettingValue("ToOBJ", "Yes") == "Yes")
        ToOBJ(folder + "\\" + name + ".obj", settings);
}

void BSPConverter::ToOBJ(const std::string& path, Settings& settings)
{
    PLX::Printer::WriteLineHeader("BSPSave", "Converting to OBJ");

    std::ofstream writer(path);

    for (auto& vertex : Vertices)
        writer << "v " << (vertex.Position.X * 2.54f) << " " << (vertex.Position.Y * 2.54f) << " " << (vertex.Position.Z * 2.54f) << "\n";
    for (auto& vertex : Vertices)
        writer << "vn " << vertex.Normal.X << " " << vertex.Normal.Y << " " << vertex.Normal.Z << "\n";
    for (auto& vertex : Vertices)
        writer << "vt " << vertex.UV.X << " " << vertex.UV.Y << "\n";


    for (auto& surface : Surfaces)
    {
        writer << "usemtl " << Materials[surface.MaterialIndex].Name << "\n";
        writer << "o "      << Materials[surface.MaterialIndex].Name << "\n";
        writer << "g "      << Materials[surface.MaterialIndex].Name << "\n";

        for (size_t i = 0; i < surface.FaceIndexCount / 3; i++)
        {
            auto drawIndex = Indices[i + (surface.FaceIndexIndex / 3)];

            writer << "f " <<
                (drawIndex.Indices[0] + surface.VertexIndex + 1) << "/" << (drawIndex.Indices[0] + surface.VertexIndex + 1) << "/" << (drawIndex.Indices[0] + surface.VertexIndex + 1) << " " <<
                (drawIndex.Indices[2] + surface.VertexIndex + 1) << "/" << (drawIndex.Indices[2] + surface.VertexIndex + 1) << "/" << (drawIndex.Indices[2] + surface.VertexIndex + 1) << " " <<
                (drawIndex.Indices[1] + surface.VertexIndex + 1) << "/" << (drawIndex.Indices[1] + surface.VertexIndex + 1) << "/" << (drawIndex.Indices[1] + surface.VertexIndex + 1) << "\n";
        }
    }
}

void WriteFaceVertex(std::ofstream& writer, const uint32_t index, const BSPConverter::D3DBSPDrawVert vertex)
{
    writer << "VERT32 " << index << "\n";
    writer << "NORMAL " << vertex.Normal.X << " " << vertex.Normal.Y << " " << vertex.Normal.Z << "\n";
    writer << "COLOR " << 
        (vertex.Color[0] / 255.0f) << " " << 
        (vertex.Color[1] / 255.0f) << " " <<
        (vertex.Color[2] / 255.0f) << " " <<
        (vertex.Color[3] / 255.0f) << "\n";
    writer << "UV 1 " << vertex.UV.X << " " << vertex.UV.Y << "\n";
}

void BSPConverter::ToXME(const std::string & path, Settings & settings)
{
    PLX::Printer::WriteLineHeader("BSPSave", "Converting to XME");

    std::ofstream writer(path);

    writer << "// Written by Zeus by Scobalula - The Yohan Killer\n";
    writer << "MODEL\n";
    writer << "VERSION 7\n\n";

    writer << "NUMBONES 1\n";
    writer << "BONE 0 -1 \"tag_origin\"\n\n";

    writer << "BONE 0\n";
    writer << "OFFSET 0.000000, 0.000000, 0.000000\n";
    writer << "X 1.000000, 0.000000, 0.000000\n";
    writer << "Y 0.000000, 1.000000, 0.000000\n";
    writer << "Z 0.000000, 0.000000, 1.000000\n";

    writer << "NUMVERTS32 " << Vertices.size() << "\n";

    size_t vertexIndex = 0;
    for (auto& vertex : Vertices)
    {
        writer << "VERT32 " << vertexIndex << "\n";
        writer << "OFFSET " << vertex.Position.X << " " << vertex.Position.Y << " " << vertex.Position.Z << "\n";
        writer << "BONES 1\n";
        writer << "BONE 0 1.000000\n";
        vertexIndex++;
    }

    size_t faceCount = 0;

    for (auto& surface : Surfaces)
        faceCount += surface.FaceIndexCount / 3;

    writer << "NUMFACES " << faceCount << "\n";

    size_t surfIndex = 0;
    for (auto& surface : Surfaces)
    {
        for (size_t i = 0; i < surface.FaceIndexCount / 3; i++)
        {
            writer << "TRI16 " << surfIndex << " " << surface.MaterialIndex << " 0 0\n";
            
            auto drawIndex = Indices[i + (surface.FaceIndexIndex / 3)];

            auto v1 = drawIndex.Indices[0] + surface.VertexIndex;
            auto v2 = drawIndex.Indices[1] + surface.VertexIndex;
            auto v3 = drawIndex.Indices[2] + surface.VertexIndex;

            WriteFaceVertex(writer, v1, Vertices[v1]);
            WriteFaceVertex(writer, v2, Vertices[v2]);
            WriteFaceVertex(writer, v3, Vertices[v3]);
        }

        surfIndex++;
    }

    writer << "\nNUMOBJECTS " << Surfaces.size() << "\n";
    for (size_t i = 0; i < Surfaces.size(); i++)
        writer << "OBJECT " << i << " " << "\"BSPMesh_" << i << "\"\n";

    writer << "\nNUMMATERIALS " << Materials.size() << "\n";

    size_t matIndex = 0;
    for (auto& material : Materials)
    {
        writer << "MATERIAL " << matIndex << " \"" << material.ToString() << "\" \"lambert\" \"TheRealZeRoY\"\n";
        writer << "COLOR 1.000000 1.000000 1.000000 1.000000\n";
        writer << "TRANSPARENCY 0.000000 0.000000 0.000000 1.000000\n";
        writer << "AMBIENTCOLOR 0.000000 0.000000 0.000000 1.000000\n";
        writer << "INCANDESCENCE 1.000000 1.000000 1.000000 1.000000\n";
        writer << "COEFFS 0.8 0.000000\n";
        writer << "GLOW 0.000000 0\n";
        writer << "REFRACTIVE 6 1.000000\n";
        writer << "SPECULARCOLOR 1.000000 1.000000 1.000000 1.000000\n";
        writer << "REFLECTIVECOLOR 1.000000 1.000000 1.000000 1.000000\n";
        writer << "REFLECTIVE -1 -1.000000\n";
        writer << "BLINN -1 -1.000000\n";
        writer << "PHONG -1.000000\n";

        matIndex++;
    }
}

void BSPConverter::LoadLumps()
{
    Lumps = Reader.ReadArray<D3DBSPLump>(Header.LumpCount);

    for (auto& lump : Lumps)
    {
        // We need the start pos to realign the reader at the end
        auto startPos = Reader.GetPosition();

#if _DEBUG
        PLX::Printer::WriteLineHeader("DEBUG", "Parsing Lump: %s", D3DBSPLumpTypeNames[lump.Type]);
        PLX::Printer::WriteLineHeader("DEBUG", "Current Position: %lli", Reader.GetPosition());
#endif
    
    
        switch (lump.Type)
        {
        case LUMP_MATERIALS:
            LoadMaterials(lump);
            PLX::Printer::WriteLineHeader("BSPLoader", "Loaded %i Materials", Materials.size());
            break;
        case LUMP_TRIANGLES:
            LoadSurfaces(lump);
            PLX::Printer::WriteLineHeader("BSPLoader", "Loaded %i Surfaces", Surfaces.size());
            break;
        case LUMP_DRAWVERTS: 
            LoadVertices(lump);
            PLX::Printer::WriteLineHeader("BSPLoader", "Loaded %i Vertices", Vertices.size());
            break;
        case LUMP_DRAWINDICES:
            LoadIndices(lump);
            PLX::Printer::WriteLineHeader("BSPLoader", "Loaded %i Indices", Indices.size());
            break;
        case LUMP_ENTITIES:
            LoadEntities(lump);
            PLX::Printer::WriteLineHeader("BSPLoader", "Loaded %i Entities (Not supported yet)", Entities.size());
            break;
        }
    
        Reader.Seek(startPos + (lump.Size + 3) & 0xFFFFFFFC);
    }
}

void BSPConverter::LoadMaterials(const D3DBSPLump lump)
{
    Materials = Reader.ReadArray<D3DBSPMaterial>(lump.Size / sizeof(D3DBSPMaterial));
}

void BSPConverter::LoadSurfaces(const D3DBSPLump lump)
{
    Surfaces = Reader.ReadArray<D3DBSPTriangle>(lump.Size / sizeof(D3DBSPTriangle));
}

void BSPConverter::LoadVertices(const D3DBSPLump lump)
{
    Vertices = Reader.ReadArray<D3DBSPDrawVert>(lump.Size / sizeof(D3DBSPDrawVert));
}

void BSPConverter::LoadIndices(const D3DBSPLump lump)
{
    Indices = Reader.ReadArray<D3DBSPDrawIndex>(lump.Size / sizeof(D3DBSPDrawIndex));
}

void BSPConverter::LoadEntities(const D3DBSPLump lump)
{
}
